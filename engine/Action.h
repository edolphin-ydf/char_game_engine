#ifndef ACTION_H_M9DNOUJS
#define ACTION_H_M9DNOUJS

#include "Drawable.h"
#include "GetterSetter.h"
#include "Timer.h"
#include "ObjectContainer.h"
#include "ActionObserver.h"
#include "ArcObject.h"
#include <vector>

namespace edolphin {


class Action : public ArcObject
{
public:
	Action (){};
	virtual ~Action (){};

	virtual void reset() = 0;
	virtual void start() = 0;
	virtual void action() = 0;
	virtual void cancel() = 0;
	virtual void finished() = 0;

	SetterGetter<Drawable*> owner = SetterGetter<Drawable*>(_owner);

protected:
	/* data */
	Drawable *_owner;
};


//
class ActionObserved : public Action
{
public:
	ActionObserved () {};
	virtual ~ActionObserved () {};

	SeterGeterRetain(ActionObserver, observer, Observer);

protected:
	/* data */
	ActionObserver* observer = nullptr;
};


//
class ActionMoveTo : public ActionObserved {
public:

#define INTERVAL 16
	ActionMoveTo(Drawable* owner, Point2D to, Millsecond duration);

	virtual ~ActionMoveTo();

	virtual void reset();

	virtual void start();

	virtual void action();

	virtual void cancel();

	virtual void finished();

public:
	double speedx;
	double speedy;
	DWORD moveTimes;
	DWORD curStep = 0;
	Point2D oripos;
	Point2D dist;
	Timer* timer = nullptr;
	Millsecond duration;
};

class ActionSequence : public ActionObserved, public ObjectContainer<ActionObserved>, public ActionObserver {
public:
	ActionSequence(bool repeat);
	ActionSequence(bool repeat, std::vector<ActionObserved*> actions);
	~ActionSequence();

	ActionSequence* addAction(ActionObserved* act);

	virtual void reset();
	virtual void start();
	virtual void action();
	virtual void cancel();
	virtual void finished();

	virtual void onFinished(ActionObserved* action);

private:
	DWORD currentActionIdx;
	bool repeat;
};


}

#endif /* end of include guard: ACTION_H_M9DNOUJS */
