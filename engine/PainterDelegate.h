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
	virtual void clean()  = 0;
	virtual void refresh() = 0;

	virtual void drawPoint(Point2D point) = 0;
	virtual void drawLine(Point2D begin, Point2D end) = 0;
	virtual void drawRectangle(Point2D leftUp, Point2D rightDown) = 0;
	virtual void drawCircles(Point2D center, int r) = 0;


	virtual void drawText(Point2D position, std::string text) = 0;
	virtual void drawPicture(Point2D position, int width, int height, BYTE *data) = 0;
	virtual void drawPicture(Point2D position, Picture *picture) = 0;

	virtual Color getBackgroundColor() = 0;
	virtual Color getForegroundColor() = 0;

	virtual void setColorPair(Color foreground, Color background) = 0;
	virtual void setBackgroundColor(Color background) = 0;
	virtual void setForegroundColor(Color foreground) = 0;

	virtual Size getViewSize()  = 0;
};

}

#endif /* end of include guard: PAINTERDELEGATE_H_2ZTOIORH */
