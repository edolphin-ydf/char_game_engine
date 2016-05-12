#include "KeyboardEventDispatcher.h"
#include "KeyboardEventListener.h"

namespace edolphin {

	KeyboardEventDispatcher::KeyboardEventDispatcher() {

	}

	KeyboardEventDispatcher::~KeyboardEventDispatcher() {

	}

	void KeyboardEventDispatcher::regist(KeyboardEventListener* listener) {
		this->addObject(listener);	
	}

	void KeyboardEventDispatcher::deRegist(KeyboardEventListener* listener) {
		this->removeObject(listener);
	}

	void KeyboardEventDispatcher::onKeyPressed(char key) {
		this->foreach([key](KeyboardEventListener* listener) { listener->onKeyPressed(key);});
	}
}
