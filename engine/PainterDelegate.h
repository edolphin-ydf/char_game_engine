#ifndef PAINTERDELEGATE_H_2ZTOIORH
#define PAINTERDELEGATE_H_2ZTOIORH

namespace edolphin {

class PainterDelegate
{
public:
	PainterDelegate ();
	virtual ~PainterDelegate ();

	virtual void init() = 0;
	virtual void destory() = 0;
	virtual void refresh() = 0;

	virtual void drawPixel() = 0;
	virtual void drawPoint() = 0;
	virtual void drawLine() = 0;
	virtual void drawRectangle() = 0;
	virtual void drawCircles() = 0;
	virtual void drawPicture(char *data) = 0;
};

}

#endif /* end of include guard: PAINTERDELEGATE_H_2ZTOIORH */
