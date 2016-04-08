#ifndef ETESTCLASS_H_XERGJKOI
#define ETESTCLASS_H_XERGJKOI

#include <list>
#include <functional>
#include <string>

class ETestClass
{
public:
	ETestClass () {};
	virtual ~ETestClass () {};

	virtual void run() = 0;

	virtual std::string getGroupName() = 0;

	virtual std::string getTestName() = 0;
};

#endif /* end of include guard: ETESTCLASS_H_XERGJKOI */
