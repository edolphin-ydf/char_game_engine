#ifndef LINE_H_SMFZQD3A
#define LINE_H_SMFZQD3A

#include "GetterSetter.h"
#include "Drawable.h"
#include "BaseType.h"

namespace edolphin {

class Line : public Drawable
{
public:
	Line (Point2D p1, Point2D p2);
	Line (int x1, int y1, int x2, int y2);
	virtual ~Line ();

	SetterGetter<int> x1 = SetterGetter<int>(_x1);
	SetterGetter<int> y1 = SetterGetter<int>(_y1);
	SetterGetter<int> x2 = SetterGetter<int>(_x2);
	SetterGetter<int> y2 = SetterGetter<int>(_y2);

	virtual void draw();	
private:
	/* data */
	int _x1, _y1;
	int _x2, _y2;
};


}

#endif /* end of include guard: LINE_H_SMFZQD3A */

