#ifndef BULLET_H_1PPEA2FG
#define BULLET_H_1PPEA2FG

#include "Drawable.h"
#include "ActionObserver.h"

namespace edolphin
{
	

class ActionMoveTo;
class Bullet : public Drawable, ActionObserver
{
public:
	Bullet (Drawable* owner);
	virtual ~Bullet ();

	virtual void onFinished(ActionObserved *act);
	virtual void onAction(ActionObserved* act);

	virtual void draw();
	virtual void onCollision(Drawable* another);
private:
	/* data */
	Drawable* owner;
	ActionMoveTo* moveTo;
};


} /* edolphin */ 

#endif /* end of include guard: BULLET_H_1PPEA2FG */
