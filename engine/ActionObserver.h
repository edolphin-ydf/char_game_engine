#ifndef ACTIONOBSERVER_H_CNSUK7TJ
#define ACTIONOBSERVER_H_CNSUK7TJ

#include "ArcObject.h"

namespace edolphin
{

class ActionObserved;
class ActionObserver: public virtual ArcObject
{
public:
	ActionObserver () {};
	virtual ~ActionObserver () {};

	virtual void onAction(ActionObserved*){}

	virtual void onStart(ActionObserved*){}
	virtual void onRestart(ActionObserved*){}
	virtual void onStop(ActionObserved*){}
	virtual void onPause(ActionObserved*){}
	virtual void onResume(ActionObserved*){}
	virtual void onFinished(ActionObserved*){}
};



} /* edolphin */ 

#endif /* end of include guard: ACTIONOBSERVER_H_CNSUK7TJ */
