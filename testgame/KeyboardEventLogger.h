#ifndef KEYBOARDEVENTLOGGER_H_EVFDQUWX
#define KEYBOARDEVENTLOGGER_H_EVFDQUWX

#include "KeyboardEventListener.h"
namespace edolphin
{


class KeyboardEventLogger : public KeyboardEventListener
{
public:
	KeyboardEventLogger () {};
	virtual ~KeyboardEventLogger () {};

	virtual void onKeyPressed(char key);
};

} /* edolphin */ 

#endif /* end of include guard: KEYBOARDEVENTLOGGER_H_EVFDQUWX */
