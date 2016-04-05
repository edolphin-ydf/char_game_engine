#ifndef PAINTERDELEGATE_H_2ZTOIORH
#define PAINTERDELEGATE_H_2ZTOIORH


#include "Point2D.h"

namespace edolphin {

class PainterDelegate
{
public:
	PainterDelegate ();
	virtual ~PainterDelegate ();

	virtual void init() = 0;
	virtual void destory() = 0;
	virtual void refresh() = 0;

	virtual void drawPoint(Point2D point) = 0;
	virtual void drawLine(Point2D begin, Point2D end) = 0;
	virtual void drawRectangle() = 0;
	virtual void drawCircles() = 0;
	virtual void drawPicture(char *data) = 0;
};

}

#endif /* end of include guard: PAINTERDELEGATE_H_2ZTOIORH */
