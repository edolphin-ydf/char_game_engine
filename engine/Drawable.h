#ifndef DRAWABLE_H_O14IJINU
#define DRAWABLE_H_O14IJINU

#include "ArcObject.h"
#include "BaseType.h"
#include "GetterSetter.h"

namespace edolphin {

struct DrableAttribute 
{
	Point2D position;
};


enum DrawableGeometryType {
	DrawableGeometryTypePoint,
	DrawableGeometryTypeLine,
	DrawableGeometryTypeRect,
	DrawableGeometryTypeCircle,
	DrawableGeometryTypePolygon,
};


class Drawable : public virtual ArcObject
{
public:
	Drawable () {};
	virtual ~Drawable () {};

	virtual void draw() = 0;
	virtual void onCollision(Drawable *another) {}
	
	virtual Rect getRect();
	virtual Size getSize(){ return size; }

	DrableAttribute getAttribute();
	void setAttribute(DrableAttribute attr);


	SetterGetter<Point2D> position = SetterGetter<Point2D>(_position);	
	SeterAssign(bool, collisionable, Collisionable);
	SeterGeterAssign(DrawableGeometryType, geometryType, GeometryType);
	bool isCollisionable() {
		return collisionable;
	}

protected:
	Point2D _position = Point2D(0, 0);
	Size size = Size(0, 0);

	DrawableGeometryType geometryType = DrawableGeometryTypeRect;
	bool collisionable = false;
};

}

#endif /* end of include guard: DRAWABLE_H_O14IJINU */
