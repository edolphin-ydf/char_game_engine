#include "Picture.h"
#include "Game.h"
#include <stdio.h>

namespace edolphin {

	
Picture::Picture () {
}

Picture::Picture(BYTE* data, DWORD width, DWORD height) {
	this->data = data;
	this->width = width;
	this->height = height;
}

Picture::~Picture () {
	SafeDeleteS(data);
}

void Picture::draw() {
	Game::getInstance()->getPainter()->drawPicture(this);
}



}
