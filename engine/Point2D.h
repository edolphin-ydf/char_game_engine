#ifndef POINT2D_H_QYWNJ450
#define POINT2D_H_QYWNJ450

namespace edolphin {

class Point2D
{
public:
	Point2D (int _x, int _y)
		:x(_x), y(_y)
	{}

	virtual ~Point2D ();

private:
	/* data */
	int x;
	int y;
};

}

#endif /* end of include guard: POINT2D_H_QYWNJ450 */

