#ifndef AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4
#define AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4

#include "Singleton.h"
#include <queue>

namespace edolphin {

class AutoReleasePool;
class AutoReleasePoolManager : public Singleton<AutoReleasePoolManager>
{
public:
	AutoReleasePool* getCurrentPool();

	void push(AutoReleasePool* pool);
	void pop();

friend class Singleton;
private:
	AutoReleasePoolManager() {}
	virtual ~AutoReleasePoolManager ();

private:
	/* data */
	std::queue<AutoReleasePool*> poolQueue;
};

}	//namespace edolphin
#endif /* end of include guard: AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4 */
