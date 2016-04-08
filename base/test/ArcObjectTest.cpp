
#include "ETestDefine.h"
#include "ArcObject.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"

using namespace edolphin;

TEST(ArcObject, retainCount) {
	ArcObject *obj = new ArcObject();
	Assert::assertEqual(obj->getRetainCount(), 1);
	obj->retain();
	Assert::assertEqual(obj->getRetainCount(), 2);
	obj->release();
	Assert::assertEqual(obj->getRetainCount(), 1);

	obj->autoRelease();

	Assert::assertEqual(obj->getRetainCount(), 2);
	AutoReleasePoolManager::deleteInstance();
	
	Assert::assertEqual(obj->getRetainCount(), 1);
}


TEST(ArcObject, autoReleasePool) {

}
