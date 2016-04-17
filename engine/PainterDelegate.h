#ifndef PAINTERDELEGATE_H_2ZTOIORH
#define PAINTERDELEGATE_H_2ZTOIORH


#include "BaseType.h"
#include "Color.h"
#include "Picture.h"

#include <string>

namespace edolphin {

class PainterDelegate
{
public:
	PainterDelegate () {};
	virtual ~PainterDelegate () {};

	virtual bool init() = 0;
	virtual void destory() = 0;
	virtual void refresh() = 0;

	virtual void drawPoint(Point2D point) = 0;
	virtual void drawLine(Point2D begin, Point2D end) = 0;
	virtual void drawRectangle(Point2D p1, Point2D p2) = 0;
	virtual void drawCircles(Point2D point, int r) = 0;
	virtual void drawText(Point2D point, std::string text) = 0;
	virtual void drawPicture(Point2D position, int width, int height, BYTE *data) = 0;
	virtual void drawPicture(Picture *picture) = 0;

	virtual Color getBackgroundColor() = 0;
	virtual Color getForegroundColor() = 0;

	virtual void setColorPair(Color foreground, Color background) = 0;
	virtual void setBackgroundColor(Color background) = 0;
	virtual void setForegroundColor(Color foreground) = 0;
};

}

#endif /* end of include guard: PAINTERDELEGATE_H_2ZTOIORH */
