#include "MainCharacter.h"
#include "Game.h"
#include "PainterDelegate.h"
#include "KeyboardEventDispatcher.h"
#include "PicLoader.h"
#include "Logger.h"
#include "Bullet.h"


namespace edolphin
{

MainCharacter::MainCharacter() {
	picture = PicLoader::load("/home/edolphin/documents/cpp/char_game_engine/testgame/res/test_pic.pic");
	this->size = Size(picture->getWidth(), picture->getHeight());

	Size size = Game::getInstance()->getPainter()->getViewSize();
	//Game::getLogger()->debug("%d %d", size.width, size.height);
	size = Size(268, 56);
	int x = size.width / 2 - picture->getWidth() / 2;
	int y = size.height - 1;
	_position = Point2D(x, y);

	KeyboardEventDispatcher::getInstance()->regist(this);
}	

void MainCharacter::onKeyPressed(char key) {
	switch (key) {
		case 'w':
			_position.y -= 1;
			break;
		case 'a':
			_position.x -= 1;
			break;
		case 's':
			_position.y += 1;
			break;
		case 'd':
			_position.x += 1;
			break;
		case ' ':
			new Bullet(this);
			break;
	}
}

void MainCharacter::draw() {
	Game::getLogger()->debug("%d %d", _position.x, _position.y);
	Game::getInstance()->getPainter()->drawPicture(_position, picture);
}

} /* edolphin */ 
