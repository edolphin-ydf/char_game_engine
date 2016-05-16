#ifndef TANKROBOT_H_C6B5PDTM
#define TANKROBOT_H_C6B5PDTM

#include "Drawable.h"
#include "ActionObserver.h"

namespace edolphin
{
	

class Picture;
class TankRobot: public Drawable, ActionObserver
{
public:
	TankRobot (int speed);
	virtual ~TankRobot ();

	virtual void draw();

	virtual void onFinished(ActionObserved* act);

private:
	void startAction();

	/* data */
	int speed;
	Picture* pic;
};


} /* edolphin */ 

#endif /* end of include guard: TANKROBOT_H_C6B5PDTM */
