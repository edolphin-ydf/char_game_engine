#ifndef POINT2D_H_QYWNJ450
#define POINT2D_H_QYWNJ450

#include "Drawable.h"
#include "GetterSetter.h"
#include "BaseType.h"


namespace edolphin {

class DPoint : public Drawable
{
public:
	DPoint (int ax, int ay)
	{
		point = Point2D(ax, ay);
	}

	virtual ~DPoint (){};

	SetterGetter<int> x = SetterGetter<int>(point.x);
	SetterGetter<int> y = SetterGetter<int>(point.y);

	virtual void draw();

private:
	Point2D point;
};

}

#endif /* end of include guard: POINT2D_H_QYWNJ450 */

