#include "Action.h"
#include "Game.h"
#include "PainterCursor.h"
#include "Logger.h"
#include <stdarg.h>
#include <algorithm>

namespace edolphin
{

bool Action::isOperationValid(Operation op)	{
	switch (op) {
		case OperationStart:
			if (state == StateWaiteToRun) {
				return true;
			}
			break;
		case OperationRestart:
			if (state == StateRunning || state == StatePause) {
				return true;
			}
			break;
		case OperationStop:
			if (state == StateRunning) {
				return true;
			}
			break;
		case OperationPause:
			if (state == StateRunning) {
				return true;
			}
			break;
		case OperationResume:
			if (state == StatePause) {
				return true;
			}
			break;
	}
	return false;
}

ActionMoveTo::ActionMoveTo(Drawable* owner, Point2D to, Millsecond duration) {
	this->dist = to;
	this->duration = duration;
	this->_owner = owner;
	owner->retain();
}

ActionMoveTo::~ActionMoveTo() {
	SafeRelease(this->_owner);
	SafeRelease(this->timer);
}

void ActionMoveTo::action() {
	curStep++;
	Point2D newPos = Point2D(oripos.x + speedx * curStep, oripos.y + speedy * curStep);
	_owner->position(newPos);
	if (curStep >= moveTimes) {
		this->finished();
	}
	observer->onAction(this);
}

void ActionMoveTo::reset() {
	curStep = 0;
	if (timer != nullptr) {
		timer->stop();
		SafeRelease(timer);
	}
	_owner->position(oripos);
}

void ActionMoveTo::start() {
	if (!isOperationValid(OperationStart)) {
		return;	
	}

	int disx = dist.x - _owner->position().x;
	int disy = dist.y - _owner->position().y;
	moveTimes = duration / INTERVAL;
	if (moveTimes == 0) {
		moveTimes = 1;
	}
	speedx = (double)disx / moveTimes;
	speedy = (double)disy / moveTimes;
	oripos = _owner->position();
	curStep = 0;

	SafeRelease(timer);
	timer = new Timer(INTERVAL, true, [this](Timer* timer, Millsecond now) { this->action(); });

	state = StateRunning;
	observer->onStart(this);
}

void ActionMoveTo::restart() {
	if (!isOperationValid(OperationRestart)) {
		return;	
	}

	reset();

	timer = new Timer(INTERVAL, true, [this](Timer* timer, Millsecond now) { this->action(); });

	state = StateRunning;
	observer->onRestart(this);
}
	
void ActionMoveTo::stop() {
	if (!isOperationValid(OperationStop)) {
		return;	
	}

	reset();

	state = StateWaiteToRun;
	observer->onStop(this);
}

void ActionMoveTo::finished() {
	if (timer != nullptr) {
		timer->stop();
	}
	_owner->position(dist);

	state = StateWaiteToRun;
	observer->onFinished(this);
}

void ActionMoveTo::pause() {
	if (!isOperationValid(OperationPause)) {
		return;	
	}

	if (timer != nullptr) {
		timer->pause();
	}

	state = StatePause;
	observer->onPause(this);
}

void ActionMoveTo::resume() {
	if (!isOperationValid(OperationResume)) {
		return;	
	}

	if (timer != nullptr) {
		timer->resume();
	}

	state = StateRunning;
	observer->onResume(this);
}




// ActionSequence
ActionSequence::ActionSequence(bool repeat) {
	this->repeat = repeat;
}

ActionSequence::ActionSequence(bool repeat, std::vector<ActionObserved*> actions) {
	std::for_each(actions.begin(), actions.end(), [this](ActionObserved* a) {a->setObserver(this); this->addObject(a);});
	this->repeat = repeat;
}

ActionSequence::~ActionSequence() {

}

ActionSequence* ActionSequence::addAction(ActionObserved* act) {
	act->setObserver(this);
	this->addObject(act);
	return this;
}

void ActionSequence::start() {
	if (!isOperationValid(OperationStart)) {
		return;	
	}

	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->start();
	}

	state = StateRunning;
}

void ActionSequence::restart() {
	if (!isOperationValid(OperationRestart)) {
		return;	
	}

	foreach([this](ActionObserved* a) { if( a != this->_objects[0]) a->stop();});
	currentActionIdx = 0;
	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->stop();
		_objects[currentActionIdx]->start();
	}

	state = StateRunning;
}


void ActionSequence::action() {
}

void ActionSequence::stop() {
	if (!isOperationValid(OperationStop)) {
		return;	
	}

	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->stop();
	}

	state = StateWaiteToRun;
}

void ActionSequence::finished() {
	state = StateWaiteToRun;
}

void ActionSequence::onFinished(ActionObserved* action) {
	currentActionIdx++;
	if (currentActionIdx >= _objects.size()) {
		if (repeat) {
			currentActionIdx = 0;
		} else {
			finished();
		}
	}

	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->start();
	}
}

void ActionSequence::pause() {
	if (!isOperationValid(OperationPause)) {
		return;	
	}

	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->pause();
	}

	state = StatePause;
}

void ActionSequence::resume() {
	if (!isOperationValid(OperationResume)) {
		return;	
	}

	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->resume();	
	}

	state = StateRunning;
}

} /* edolphin */ 




