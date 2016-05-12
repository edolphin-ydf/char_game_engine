#include "RWLock.h"

namespace edolphin
{
	

RWLock::RWLock() {

}

RWLock::~RWLock() {

}

void RWLock::rlock() {
	std::lock_guard<std::mutex> scopeLock(internalLock);

	if (rcnt > 0) {
		rcnt++;
	} else {
		lock.lock();
	}
}

void RWLock::runlock() {
	std::lock_guard<std::mutex> scopeLock(internalLock);
	rcnt--;
	if (rcnt == 0) {
		lock.unlock();
	}
}
	
void RWLock::wlock() {
	lock.lock();
}

void RWLock::wunlock() {
	lock.unlock();
}



} /* edolphin */ 
