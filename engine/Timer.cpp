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
	TimerManager::getInstance()->addObject(this);
}

Timer::Timer(Millsecond interval, bool repeat, std::function<Callback> callback, ArcObject* userdata) {
	this->interval = interval;
	this->repeat = repeat;
	this->callback = callback;
	this->userdata = userdata;
	userdata->retain();
	TimerManager::getInstance()->addObject(this);
}

Timer::~Timer() {
	userdata->release();
	runTimes++;
}

void Timer::onTimer(Millsecond now) {
	callback(this, now);
	lastCallTime = now;
}

} /* edolphin */ 
