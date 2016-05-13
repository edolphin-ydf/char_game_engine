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




class Drawable : public ArcObject
{
public:
	Drawable () {};
	virtual ~Drawable () {};

	virtual void draw() = 0;
	virtual Size getSize(){ return size; }

	SetterGetter<Point2D> position = SetterGetter<Point2D>(_position);	

	DrableAttribute getAttribute();
	void setAttribute(DrableAttribute attr);

protected:
	Point2D _position = Point2D(0, 0);
	Size size;
};

}

#endif /* end of include guard: DRAWABLE_H_O14IJINU */
