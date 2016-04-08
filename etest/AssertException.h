#ifndef ASSERTEXCEPTION_H_FB5MUQPH
#define ASSERTEXCEPTION_H_FB5MUQPH

#include <string>

class AssertException
{
public:
	AssertException ();
	AssertException (const char* errMsg);
	virtual ~AssertException ();

	std::string toString();
private:
	std::string errMsg;
};

#endif /* end of include guard: ASSERTEXCEPTION_H_FB5MUQPH */
