#include "CollisionDetection.h"

namespace edolphin
{
	
bool CollisionDetection::CollisionDectectionRectRect(Rect a, Rect b) {
	Point2D c1 = a.getCenter();
	Point2D c2 = b.getCenter();	

	if (fabs((float)(c1.x - c2.x)) < a.size.width / 2.0 + b.size.width / 2.0) {
		if (fabs((float)(c1.y - c2.y)) < a.size.height / 2.0 + b.size.height / 2.0) {
			return true;	
		}	
	}
	return false;
}

bool CollisionDetection::CollisionDectectionRectPoint(Rect r, Point2D p) {
	if (p.x <= r.position.x + r.size.width
			&& p.x >= r.position.x
			&& p.y >= r.position.y
			&& p.y <= r.position.y + r.size.height) {
		return true;
	}
	return false;
}

bool CollisionDetection::CollisionDetectionRectCircle(Rect r, Circle c) {
	return false;
}


} /* edolphin */ 
