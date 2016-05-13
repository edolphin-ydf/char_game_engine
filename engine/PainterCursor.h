#ifndef PAINTERCURSOR_H_UMMGU3R5
#define PAINTERCURSOR_H_UMMGU3R5

#include "PainterDelegate.h"

namespace edolphin {
class PainterCursor : public PainterDelegate
{
public:
	PainterCursor ();
	virtual ~PainterCursor ();

	virtual bool init();
	virtual void destory();
	virtual void clean();
	virtual void refresh();

	virtual void drawPoint(Point2D point);
	virtual void drawPoint(int x, int y);
	virtual void drawLine(Point2D begin, Point2D end);
	virtual void drawRectangle(Point2D leftUp, Point2D rightDown);
	virtual void drawCircles(Point2D center, int r);

	virtual void drawText(Point2D position, std::string text);
	virtual void drawPicture(Point2D position, int width, int height, BYTE *data);
	virtual void drawPicture(Point2D position, Picture *picture);

	virtual Color getBackgroundColor();
	virtual Color getForegroundColor();

	virtual void setColorPair(Color foreground, Color background);
	virtual void setBackgroundColor(Color background);
	virtual void setForegroundColor(Color foreground);

	virtual Size getViewSize();
private:
	/* data */
	Color _foregroundColor = Color::white;
	Color _backgroundColor = Color::black;
};

}

#endif /* end of include guard: PAINTERCURSOR_H_UMMGU3R5 */
