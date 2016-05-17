#ifndef COLLISIONDETECTION_H_J9ZZGNWQ
#define COLLISIONDETECTION_H_J9ZZGNWQ

#include "BaseType.h"

namespace edolphin
{
	
class CollisionDetection
{
public:
	CollisionDetection () {};
	virtual ~CollisionDetection () {};

	static bool CollisionDectectionRectRect(Rect a, Rect b);

	static bool CollisionDectectionRectPoint(Rect r, Point2D p);

	static bool CollisionDetectionRectCircle(Rect r, Circle c);
};



} /* edolphin */ 

#endif /* end of include guard: COLLISIONDETECTION_H_J9ZZGNWQ */
