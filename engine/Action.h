#ifndef ACTION_H_M9DNOUJS
#define ACTION_H_M9DNOUJS

#include "Drawable.h"
#include "GetterSetter.h"
#include "Timer.h"

namespace edolphin {


class Action
{
public:
	Action ();
	virtual ~Action ();

	virtual void start() = 0;
	virtual void action() = 0;
	virtual void cancel() = 0;
	virtual void finished() = 0;

	SetterGetter<Drawable*> owner = SetterGetter<Drawable*>(_owner);

protected:
	/* data */
	Drawable *_owner;
};


class ActionMoveTo : public Action {
public:
	ActionMoveTo(Drawable* owner, Point2D to, DWORD duration) {
		this->_owner = owner;
		DWORD disx = to.x - owner->position().x;
		DWORD disy = to.y - owner->position().y;
		DWORD fps = 60;
		DWORD mspf = 1000 / fps;
		DWORD fnum = duration / mspf;
		moveTimes = fnum;
		speedx = disx / fnum;
		speedy = disy / fnum;
		oripos = owner->position();
	}

	virtual void start() {

	}

	virtual void action() {
		curStep++;
		Point2D newPos = Point2D(oripos.x + speedx * curStep, oripos.y + speedy * curStep);
		_owner->position(newPos);
	}

	virtual void cancel() {

	}

	virtual void finished() {

	}

public:
	DWORD speedx;
	DWORD speedy;
	DWORD moveTimes;
	DWORD curStep = 0;
	Point2D oripos;
};

}

#endif /* end of include guard: ACTION_H_M9DNOUJS */
