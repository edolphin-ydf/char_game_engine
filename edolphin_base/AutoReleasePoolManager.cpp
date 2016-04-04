#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"
#include "ArcObject.h"

namespace edolphin {

AutoReleasePoolManager* AutoReleasePoolManager::poolManager = new AutoReleasePoolManager();

AutoReleasePoolManager* AutoReleasePoolManager::getInstance() {
	if (poolManager == nullptr) {
		poolManager = new AutoReleasePoolManager();
	}
	return poolManager;
}

void AutoReleasePoolManager::deleteInstance() {
	SafeDelete(poolManager);
}

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


}

