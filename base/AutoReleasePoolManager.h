#ifndef AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4
#define AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4

#include <queue>

namespace edolphin {

class AutoReleasePool;
class AutoReleasePoolManager
{
public:
	static AutoReleasePoolManager* getInstance();
	static void deleteInstance();
	AutoReleasePool* getCurrentPool();

	void push(AutoReleasePool* pool);
	void pop();

private:
	AutoReleasePoolManager ();
	virtual ~AutoReleasePoolManager ();

private:
	/* data */
	std::queue<AutoReleasePool*> poolQueue;
	static AutoReleasePoolManager* poolManager;
};

}	//namespace edolphin
#endif /* end of include guard: AUTORELEASEPOOLMANAGER_H_1ZCE5OJ4 */
