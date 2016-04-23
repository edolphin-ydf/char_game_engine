#include "Action.h"
#include "Game.h"
#include "PainterCursor.h"
#include "Logger.h"
#include <stdarg.h>
#include <algorithm>

namespace edolphin
{
	

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

void ActionMoveTo::reset() {
	curStep = 0;
	timer->stop();
	SafeRelease(timer);
	observer->onReset(this);
}

void ActionMoveTo::action() {
	curStep++;
	Point2D newPos = Point2D(oripos.x + speedx * curStep, oripos.y + speedy * curStep);
	_owner->position(newPos);
	if (curStep >= moveTimes) {
		this->finished();
	}
}

void ActionMoveTo::start() {
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
	observer->onStart(this);
}
	
void ActionMoveTo::cancel() {
	timer->stop();
	observer->onCancel(this);
}

void ActionMoveTo::finished() {
	timer->stop();
	_owner->position(dist);
	observer->onFinished(this);
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

void ActionSequence::reset() {
	foreach([this](ActionObserved* a) {a->reset();});
	currentActionIdx = 0;
}

void ActionSequence::start() {
	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->start();
	}
}

void ActionSequence::action() {
}

void ActionSequence::cancel() {
	if (currentActionIdx < _objects.size()) {
		_objects[currentActionIdx]->cancel();
	}
}

void ActionSequence::finished() {
}

void ActionSequence::onFinished(ActionObserved* action) {
	currentActionIdx++;
	if (currentActionIdx >= _objects.size() && repeat) {
		currentActionIdx = 0;
	}
	start();
}

} /* edolphin */ 




