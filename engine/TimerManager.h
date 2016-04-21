#ifndef TIMERMANAGER_H_HZ2O5TGQ
#define TIMERMANAGER_H_HZ2O5TGQ

#include "ObjectContainer.h"
#include "BaseType.h"
#include "Singleton.h"

namespace edolphin
{

class Timer;
class TimerManager : public ObjectContainer<Timer>, public Singleton<TimerManager>
{
public:

	void onTimer(Millsecond now);
private:
	friend class Singleton;
	TimerManager ();
	virtual ~TimerManager ();
};

} /* edolphin */ 

#endif /* end of include guard: TIMERMANAGER_H_HZ2O5TGQ */
