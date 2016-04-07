#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"
#include "ArcObject.h"

namespace edolphin {

AutoReleasePool* AutoReleasePoolManager::getCurrentPool() {
	return poolQueue.front();
}

void AutoReleasePoolManager::push(AutoReleasePool* pool) {
	poolQueue.push(pool);
}

void AutoReleasePoolManager::pop() {
	AutoReleasePool* pool = poolQueue.front();
	pool->release();
	poolQueue.pop();
	delete pool;
}

AutoReleasePoolManager::~AutoReleasePoolManager () {
	while(!poolQueue.empty()) {
		AutoReleasePool* pool = poolQueue.front();
		poolQueue.pop();
		delete pool;
	}
}

}

