#ifndef PAINTERCURSOR_H_UMMGU3R5
#define PAINTERCURSOR_H_UMMGU3R5

#include "PainterDelegate.h"

namespace edolphin {
class PainterCursor : public PainterDelegate
{
public:
	PainterCursor ();
	virtual ~PainterCursor ();

	virtual void init();
	virtual void destory();
	virtual void refresh();

	virtual void drawPixel();
	virtual void drawPoint();
	virtual void drawLine();
	virtual void drawRectangle();
	virtual void drawCircles();
	virtual void drawPicture(char *data);

private:
	/* data */
};

}

#endif /* end of include guard: PAINTERCURSOR_H_UMMGU3R5 */
