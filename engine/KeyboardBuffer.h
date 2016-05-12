#ifndef KEYBOARDBUFFER_H_KIUFRN8G
#define KEYBOARDBUFFER_H_KIUFRN8G

#include "Singleton.h"
#include <queue>
#include <mutex>

namespace edolphin {

class KeyboardBuffer
{
public:
	KeyboardBuffer () {};
	virtual ~KeyboardBuffer (){};

	// thread safe
	void push(char key);
	char pop();

private:

	/* data */
	std::queue<char> buffer;
	std::mutex bufferLock;
};
}

#endif /* end of include guard: KEYBOARDBUFFER_H_KIUFRN8G */
