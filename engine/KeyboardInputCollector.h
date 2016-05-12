#ifndef KEYBOARDINPUTCOLLECTOR_H_8VBJW1ZE
#define KEYBOARDINPUTCOLLECTOR_H_8VBJW1ZE

#include <thread>

namespace edolphin
{


class KeyboardInputCollector
{
public:
	KeyboardInputCollector ();
	virtual ~KeyboardInputCollector ();

	void run();

	void collect();

	void final();

private:
	/* data */
	std::thread collectThread;

	volatile bool finished = false;
};


} /* edolphin */ 

#endif /* end of include guard: KEYBOARDINPUTCOLLECTOR_H_8VBJW1ZE */
