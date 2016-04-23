#include "Timer.h"
#include "TimerManager.h"

namespace edolphin
{


Timer::Timer() {

}	

Timer::Timer(Millsecond interval, bool repeat, std::function<Callback> callback) {
	this->interval = interval;
	this->repeat = repeat;
	this->callback = callback;
	TimerManager::getInstance()->hireTimer(this);
}

Timer::Timer(Millsecond interval, bool repeat, std::function<Callback> callback, ArcObject* userdata) {
	this->interval = interval;
	this->repeat = repeat;
	this->callback = callback;
	this->userdata = userdata;
	userdata->retain();
	TimerManager::getInstance()->hireTimer(this);
}

Timer::~Timer() {
	userdata->release();
}

void Timer::onTimer(Millsecond now) {
	callback(this, now);
	runTimes++;
	lastCallTime = now;
}

void Timer::pause() {
	TimerManager::getInstance()->fireTimer(this);
}

void Timer::resume() {
	TimerManager::getInstance()->hireTimer(this);
}

void Timer::stop() {
	TimerManager::getInstance()->fireTimer(this);
	this->runTimes = 0;
	this->lastCallTime = 0;
}

} /* edolphin */ 
