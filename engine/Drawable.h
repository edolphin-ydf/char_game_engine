#ifndef DRAWABLE_H_O14IJINU
#define DRAWABLE_H_O14IJINU

#include "ArcObject.h"
#include "BaseType.h"
#include "GetterSetter.h"

namespace edolphin {

class Drawable : public ArcObject
{
public:
	Drawable () {};
	virtual ~Drawable () {};

	virtual void draw() = 0;

	SetterGetter<Point2D> position = SetterGetter<Point2D>(_position);	
protected:
	Point2D _position = Point2D(0, 0);
};

}

#endif /* end of include guard: DRAWABLE_H_O14IJINU */
