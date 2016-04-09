#ifndef POINT2D_H_QYWNJ450
#define POINT2D_H_QYWNJ450

#include "GetterSetter.h"
namespace edolphin {

class Point2D
{
public:
	Point2D (int ax, int ay)
		:_x(ax), _y(ay)
	{}

	virtual ~Point2D (){};

	SetterGetter<int> x = SetterGetter<int>(_x);
	SetterGetter<int> y = SetterGetter<int>(_y);

	Point2D operator - (Point2D b) {
		return Point2D(_x - b._x, _y - b._y);
	}
	
	Point2D operator + (Point2D b) {
		return Point2D(_x + b._x, _y + b._y);
	}


private:
	/* data */
	int _x;
	int _y;
};

}

#endif /* end of include guard: POINT2D_H_QYWNJ450 */

