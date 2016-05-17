#include "Bullet.h"
#include "Action.h"
#include "Game.h"
#include "PainterCursor.h"

namespace edolphin
{
	

Bullet::Bullet(Drawable* owner) {
	collisionable = true;
	geometryType = DrawableGeometryTypePoint;

	_position = owner->position();
	_position.x += owner->getSize().width / 2;	
	
	Point2D to = Point2D(_position.x, 0);
	double dist = _position.y;
	double speed = 60.0;
	Millsecond duration = dist / speed * 1000.0;	
	moveTo = new ActionMoveTo(this, to, duration);
	moveTo->setObserver(this);
	moveTo->start();
	Game::getInstance()->getScene()->addObject(this);
}

Bullet::~Bullet() {
	SafeRelease(moveTo);
}

void Bullet::onFinished(ActionObserved* act) {
	Game::getInstance()->getScene()->removeObject(this);
	Drawable::release();
}
	
void Bullet::onAction(ActionObserved* act) {

}

void Bullet::draw() {
	Game::getInstance()->getPainter()->drawPoint(_position);
}

void Bullet::onCollision(Drawable* another) {

}


} /* edolphin */ 
