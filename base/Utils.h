#ifndef UTILS_H_O17MLQSG
#define UTILS_H_O17MLQSG

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

namespace edolphin {

class Utils
{
public:
	Utils ();
	virtual ~Utils ();

	static unsigned long getMillionTimeStamp() {
		struct timeval time;
		gettimeofday(&time, nullptr);
		return time.tv_sec * 1000 + time.tv_usec/1000;
	}

	static unsigned long getTimeStamp() {
		return time(nullptr);
	}

	static int randBetween(int a, int b) {
		if (a == b) {
			return a;
		}
		if (a > b) {
			std::swap(a, b);
		}
		return rand() % (b - a + 1) + a;
	}
};

}
#endif /* end of include guard: UTILS_H_O17MLQSG */
