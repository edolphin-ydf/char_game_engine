#include "KeyboardBuffer.h"

namespace edolphin
{
	
void KeyboardBuffer::push(char key) {
	std::lock_guard<std::mutex> scopeLock(bufferLock);

	buffer.push(key);
}

char KeyboardBuffer::pop() {
	std::lock_guard<std::mutex> scopeLock(bufferLock);

	if (buffer.empty()) {
		return 0;	
	}
 	char res = buffer.front();
	buffer.pop();
	return res;
}

} /* edolphin */ 
