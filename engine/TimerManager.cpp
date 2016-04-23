#include "TimerManager.h"
#include "Timer.h"
#include <vector>
#include <algorithm>

namespace edolphin
{
	
TimerManager::TimerManager() {

}

TimerManager::~TimerManager() {

}

void TimerManager::onTimer(Millsecond now) {
	std::for_each(willHireTimers.begin(), willHireTimers.end(), [this](Timer* timer){ this->addObject(timer); 
			timer->release();}); 
	willHireTimers.clear();

	for (auto timer : _objects) {
		if (timer->isRepeat() || (!timer->isRepeat() &&timer->getRunTimes() == 0)) {
			if (timer->getLastCallTime() + timer->getInterval() < now) {
				timer->onTimer(now); 
			}
		} else {
			willFireTimers.push_back(timer);
		}
	}

	std::for_each(willFireTimers.begin(), willFireTimers.end(), [this](Timer* timer){ this->removeObject(timer);
			timer->release();} );
	willFireTimers.clear();
}

void TimerManager::fireTimer(Timer *timer) {
	this->willFireTimers.push_back(timer);
	timer->retain();
}

void TimerManager::hireTimer(Timer* timer) {
	this->willHireTimers.push_back(timer);
	timer->retain();
}

} /* edolphin */ 
