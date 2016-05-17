#ifndef KEYBOARDEVENTLISTENER_H_D0MYDJHC
#define KEYBOARDEVENTLISTENER_H_D0MYDJHC

#include "ArcObject.h"

namespace edolphin {


class KeyboardEventListener : public virtual ArcObject
{
public:
	KeyboardEventListener (){};
	virtual ~KeyboardEventListener (){};

	virtual void onKeyPressed(char key) = 0;
};

}
#endif /* end of include guard: KEYBOARDEVENTLISTENER_H_D0MYDJHC */
