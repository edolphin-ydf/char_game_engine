#include "PainterCursor.h"

#include <curses.h>

namespace edolphin {

PainterCursor::PainterCursor (){

}

PainterCursor::~PainterCursor () {

}

void PainterCursor::init() {
	initscr();	
	use_default_colors();	// black backgroupd and white forground
	noecho();	// no echo with input
	cbreak();	// no need for cr

}

void PainterCursor::destory() {
	endwin();
}

void PainterCursor::refresh() {

}

void PainterCursor::drawPixel() {

}

void PainterCursor::drawPoint() {

}

void PainterCursor::drawLine() {

}

void PainterCursor::drawRectangle() {

}

void PainterCursor::drawCircles() {

}

void PainterCursor::drawPicture(char *data) {

}

}
