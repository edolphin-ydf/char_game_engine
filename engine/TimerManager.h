#ifndef TIMERMANAGER_H_HZ2O5TGQ
#define TIMERMANAGER_H_HZ2O5TGQ

#include "ObjectContainer.h"
#include "BaseType.h"
#include "Singleton.h"
#include "vector"

namespace edolphin
{

class Timer;
class TimerManager : protected ObjectContainer<Timer>, public Singleton<TimerManager>
{
public:

	void onTimer(Millsecond now);

	void fireTimer(Timer* timer);

	void hireTimer(Timer* timer);
private:
	friend class Singleton;
	TimerManager ();
	virtual ~TimerManager ();

	std::vector<Timer*> willFireTimers;
	std::vector<Timer*> willHireTimers;
};

} /* edolphin */ 

#endif /* end of include guard: TIMERMANAGER_H_HZ2O5TGQ */
