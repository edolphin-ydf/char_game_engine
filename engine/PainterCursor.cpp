#include "PainterCursor.h"

#include <curses.h>
#include <math.h> 
#include <stdio.h>

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
	drawPoint(point.x, point.y);
}

void PainterCursor::drawPoint(int x, int y) {
	mvaddch(y, x, '*');
}

void PainterCursor::drawLine(Point2D begin, Point2D end) {
	Point2D tmp = end - begin;	
	double k = (double)tmp.y / (double)tmp.x;
	for (int i=0; i<= tmp.x; ++i) {
		int y = round(k * i) + begin.y;
		int x = i + begin.x;
		drawPoint(x, y);
	}
}

void PainterCursor::drawRectangle(Point2D p1, Point2D p2) {
	int width = p2.x - p1.x;
	int height = p2.y - p1.y;
	mvvline(p1.y, p1.x, '|', height);
	mvvline(p1.y, p2.x, '|', height);
	mvhline(p1.y, p1.x, '-', width);
	mvhline(p2.y, p1.x, '-', width);
}

void PainterCursor::drawCircles(Point2D point, int r) {

}

void PainterCursor::drawText(Point2D point, std::string text) {
	mvprintw(point.y, point.x, text.c_str());
}

void PainterCursor::drawPicture(Point2D position, int width, int height, BYTE *data) {
	for (int i = 0; i < height; ++i) {
		mvprintw(position.y + i, position.x, (char*)(data + width * i));
	}
}

void PainterCursor::drawPicture(Point2D position, Picture *picture) {
	drawPicture(position, picture->getWidth(), picture->getHeight(), picture->getData());
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
