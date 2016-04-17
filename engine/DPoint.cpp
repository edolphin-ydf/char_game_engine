#include "DPoint.h"
#include "Game.h"


namespace edolphin {

void DPoint::draw() {
	Game::getInstance()->getPainter()->drawPoint(point + _position);
}

}
