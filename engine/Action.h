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

	virtual void start() = 0;
	virtual void restart() = 0;
	virtual void stop() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void finished() = 0;

	SetterGetter<Drawable*> owner = SetterGetter<Drawable*>(_owner);

protected:
	/* data */
	Drawable *_owner;
	virtual void action() = 0;
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
	
	virtual void start();
	virtual void restart();
	virtual void stop();
	virtual void pause();
	virtual void resume();
	virtual void finished();

protected:
	virtual void action();

private:
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

	virtual void start();
	virtual void restart();
	virtual void stop();
	virtual void pause();
	virtual void resume();
	virtual void finished();

	virtual void onFinished(ActionObserved* action);

protected:
	virtual void action();

private:
	DWORD currentActionIdx;
	bool repeat;
};


}

#endif /* end of include guard: ACTION_H_M9DNOUJS */
