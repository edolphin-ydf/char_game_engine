#include "GameObject.h"
#include "Picture.h"
#include "Game.h"
#include "PainterDelegate.h"
#include "PicLoader.h"

namespace edolphin
{
	
	
PicObject::PicObject(const char* path) {
	this->pic = PicLoader::load(path);
}

PicObject::PicObject(Picture* picture) {
	this->pic = picture;
	picture->retain();
}

PicObject::~PicObject() {
	SafeRelease(this->pic);
}


void PicObject::draw() {
	if (pic != nullptr) {
		Game::getInstance()->getPainter()->drawPicture(_position, pic);
	}
}

} /* edolphin */ 
