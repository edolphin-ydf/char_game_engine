#include "ArcObject.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"

#include <sstream>

namespace edolphin {

ArcObject::ArcObject(void)
{
	retainCount = 1;
}


ArcObject::~ArcObject(void)
{
}

void ArcObject::retain(){
	retainCount++;
}

void ArcObject::release(){
	retainCount--;
	if(retainCount <= 0){
		delete this;
	}
}

void ArcObject::autoRelease() {
	AutoReleasePoolManager::getInstance()->getCurrentPool()->autoRelease(this);
}

bool ArcObject::isEqualTo(ArcObject *obj){
	return this == obj;
}

std::string ArcObject::toString() {
	std::ostringstream oss;
	oss<<"{"<< retainCount <<"}";
	return oss.str();
}

}	// namespace edolphin

