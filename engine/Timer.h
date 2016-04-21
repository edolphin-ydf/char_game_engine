#ifndef TIMER_H_BM1TXBIL
#define TIMER_H_BM1TXBIL

#include "BaseType.h"
#include "ArcObject.h"
#include <functional>

namespace edolphin 
{

class Timer: public ArcObject
{
public:
	typedef void(Callback)(Timer*, Millsecond);
public:
	Timer ();
	Timer(Millsecond interval, bool repeat, std::function<Callback> callback);
	Timer(Millsecond interval, bool repeat, std::function<Callback> callback, ArcObject* userdata);
	virtual ~Timer ();

	void onTimer(Millsecond now);

private:
	/* data */
	Millsecond interval = 0;
	bool repeat = true;
	ArcObject* userdata = nullptr;
	std::function<Callback> callback;
	DWORD runTimes = 0;
	Millsecond lastCallTime = 0;

	SeterGeterAssign(Millsecond, interval, Interval);
	SeterGeterAssign(bool, repeat, Repeat);
	SeterGeterRetain(ArcObject, userdata, Userdata);
	GeterAssign(DWORD, runTimes, RunTimes);
	SeterGeterAssign(Millsecond, lastCallTime, LastCallTime);

public:
	bool isRepeat() {
		return repeat;
	}
};
} /* edolphin */ 

#endif /* end of include guard: TIMER_H_BM1TXBIL */
