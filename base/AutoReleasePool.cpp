#include "AutoReleasePool.h"
#include "ArcObject.h"

namespace edolphin {

void AutoReleasePool::release() {
	PoolType_IT it = pool.begin();
	for (; it != pool.end(); ++it) {
		(*it)->release();	
	}
	pool.clear();
}

void AutoReleasePool::autoRelease(ArcObject *arcObject) {
	if (arcObject != NULL) {
		arcObject->retain();
		pool.push_back(arcObject);
	}
}

AutoReleasePool::~AutoReleasePool() {
	release();
}

}	// namespace edolphin
