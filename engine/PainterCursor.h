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
	virtual void refresh();

	virtual void drawPoint(Point2D point);
	virtual void drawPoint(int x, int y);
	virtual void drawLine(Point2D begin, Point2D end);
	virtual void drawRectangle(Point2D p1, Point2D p2);
	virtual void drawCircles(Point2D point, int r);
	virtual void drawText(Point2D point, std::string text);
	virtual void drawPicture(int width, int height, char *data);

	virtual Color getBackgroundColor();
	virtual Color getForegroundColor();

	virtual void setColorPair(Color foreground, Color background);
	virtual void setBackgroundColor(Color background);
	virtual void setForegroundColor(Color foreground);

private:
	/* data */
	Color _foregroundColor = Color::white;
	Color _backgroundColor = Color::black;
};

}

#endif /* end of include guard: PAINTERCURSOR_H_UMMGU3R5 */
