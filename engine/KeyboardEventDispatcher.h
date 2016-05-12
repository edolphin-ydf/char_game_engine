#ifndef KEYBOARDEVENTDISPATCHER_H_TDV6I4SG
#define KEYBOARDEVENTDISPATCHER_H_TDV6I4SG

#include "ObjectContainer.h"
#include "Singleton.h"

namespace edolphin {

class KeyboardEventListener;
class KeyboardEventDispatcher : public ObjectContainer<KeyboardEventListener> , 
	public Singleton<KeyboardEventDispatcher>
{
public:

	void regist(KeyboardEventListener* listener);
	void deRegist(KeyboardEventListener* listener);

	void onKeyPressed(char key);

private:
	friend class Singleton;
	KeyboardEventDispatcher ();
	virtual ~KeyboardEventDispatcher ();
};

}

#endif /* end of include guard: KEYBOARDEVENTDISPATCHER_H_TDV6I4SG */
