#ifndef ACTIONOBSERVER_H_CNSUK7TJ
#define ACTIONOBSERVER_H_CNSUK7TJ

#include "ArcObject.h"
namespace edolphin
{

class ActionObserved;
class ActionObserver : public ArcObject
{
public:
	ActionObserver () {};
	virtual ~ActionObserver () {};

	virtual void onReset(ActionObserved*){}
	virtual void onStart(ActionObserved*){}
	virtual void onAction(ActionObserved*){}
	virtual void onCancel(ActionObserved*){}
	virtual void onFinished(ActionObserved*){}
};



} /* edolphin */ 

#endif /* end of include guard: ACTIONOBSERVER_H_CNSUK7TJ */
