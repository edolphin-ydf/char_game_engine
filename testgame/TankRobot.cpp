#include "TankRobot.h"
#include "Picture.h"
#include "PicLoader.h"
#include "Game.h"
#include "PainterDelegate.h"
#include "Action.h"
#include "Utils.h"
#include "TestScene.h"

namespace edolphin
{
	
TankRobot::TankRobot(int speed) {
	pic = PicLoader::load("/home/edolphin/documents/cpp/char_game_engine/testgame/res/test_pic.pic");
	startAction();
	((TestScene*)Game::getInstance()->getScene())->addTankRobot(this);
}

TankRobot::~TankRobot() {
	((TestScene*)Game::getInstance()->getScene())->removeTankRobot(this);
}

void TankRobot::draw() {
	Game::getInstance()->getPainter()->drawPicture(_position, pic);
}

void TankRobot::onFinished(ActionObserved* act) {
	act->release();
	startAction();
}

void TankRobot::startAction() {
	static Point2D direction[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	int dir = Utils::randBetween(0, 3);
	Size screenSize = Game::getInstance()->getPainter()->getViewSize();
	int deltaX = Utils::randBetween(0, screenSize.width);
	int deltaY = Utils::randBetween(0, screenSize.width);
	Point2D delta = Point2D(direction[dir].x * deltaX, direction[dir].y * deltaY);
	Point2D to = _position + delta;
	if (to.x > screenSize.width - this->size.width) {
		to.x = screenSize.width - this->size.width;
	}
	if (to.y > screenSize.height - this->size.height) {
		to.y = screenSize.height - this->size.height;
	}

	double dist = _position.distance(to);
	Millsecond duration  = dist / (double)speed * 1000;
	ActionMoveTo *moveTo = new ActionMoveTo(this, to, duration);
	moveTo->start();
}

} /* edolphin */ 
