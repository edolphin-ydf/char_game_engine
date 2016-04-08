#ifndef AUTORELEASEPOOL_H_H4N6EYD7
#define AUTORELEASEPOOL_H_H4N6EYD7

#include <list>

namespace edolphin {

class ArcObject;
class AutoReleasePool
{
public:
	AutoReleasePool () {};
	virtual ~AutoReleasePool ();

	void release();
	void autoRelease(ArcObject *arcObject);


private:
	typedef std::list<ArcObject*> PoolType;
	typedef PoolType::iterator PoolType_IT;
	PoolType pool;	
};

}	//namespace edolphin
#endif /* end of include guard: AUTORELEASEPOOL_H_H4N6EYD7 */
