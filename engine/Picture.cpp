#include "Picture.h"
#include "Game.h"

namespace edolphin {

	
Picture::Picture () {
}

Picture::Picture(BYTE* data, DWORD width, DWORD height) {
	_data = data;
	_width = width;
	_height = height;
}

Picture::~Picture () {
	SafeDelete(_data);
}

void Picture::draw() {
	Game::getInstance()->getPainter()->drawPicture(this);
}



}
