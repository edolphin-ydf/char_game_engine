#include "AssertException.h"


AssertException::AssertException () {
	this->errMsg = "undefine err";
}

AssertException::AssertException (const char* errMsg) {
	this->errMsg = errMsg;
}
	
AssertException::~AssertException (){

}

std::string AssertException::toString() {
	return "AssertException:" + errMsg;
}
