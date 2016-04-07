#include "PainterCursor.h"

#include <curses.h>

namespace edolphin {

PainterCursor::PainterCursor (){
}

PainterCursor::~PainterCursor () {

}

bool PainterCursor::init() {
	initscr();	
	if (!has_colors()) {
		return false;	
	}
	use_default_colors();	// black backgroupd and white forground
	noecho();	// no echo with input
	cbreak();	// no need for cr
	return true;
}

void PainterCursor::destory() {
	endwin();
}

void PainterCursor::refresh() {
	::refresh();
}

void PainterCursor::drawPoint(Point2D point) {

}

void PainterCursor::drawLine(Point2D begin, Point2D end) {

}

void PainterCursor::drawRectangle(Point2D p1, Point2D p2) {

}

void PainterCursor::drawCircles(Point2D point, int r) {

}

void PainterCursor::drawText(Point2D point, std::string text) {

}

void PainterCursor::drawPicture(int width, int height, char *data) {

}


Color PainterCursor::getBackgroundColor() {
	return _backgroundColor;	
}

Color PainterCursor::getForegroundColor() {
	return _foregroundColor;
}


void PainterCursor::setColorPair(Color foreground, Color background) {
	_foregroundColor = foreground;
	_backgroundColor = background;
}

void PainterCursor::setBackgroundColor(Color background) {
	_backgroundColor = background;
}

void PainterCursor::setForegroundColor(Color foreground) {
	_foregroundColor = foreground;
}


}
