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
	std::vector<Timer*> removeList;
	for (auto timer : _objects) {
		if (timer->isRepeat() || (!timer->isRepeat() &&timer->getRunTimes() == 0)) {
			if (timer->getLastCallTime() + timer->getInterval() < now) {
				timer->onTimer(now); 
			}
		} else {
			removeList.push_back(timer);
		}
	}

	std::for_each(removeList.begin(), removeList.end(), [this](Timer* timer){ this->removeObject(timer);} );
}


} /* edolphin */ 
