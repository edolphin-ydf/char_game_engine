#include "Line.h"
#include "Game.h"

namespace edolphin {

Line::Line (Point2D p1, Point2D p2) {
	_x1 = p1.x;
	_y1 = p1.y;
	_x2 = p2.x;
	_y2 = p2.y;
}

Line::Line (int x1, int y1, int x2, int y2) {
	this->_x1 = x1;
	this->_y2 = y2;
	this->_x2 = x2;
	this->_y1 = y1;

}

Line::~Line () {

}

void Line::draw() {
	Game::getInstance()->getPainter()->drawLine(Point2D(_x1, _y1), Point2D(_x2, _y2));
}

}
