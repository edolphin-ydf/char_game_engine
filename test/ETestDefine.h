#ifndef ETESTDEFINE_H_HULND5UB
#define ETESTDEFINE_H_HULND5UB

#include "ETest.h"
#include "ETestClass.h"
#include "TestCaseManager.h"

#define TEST_CLASS_NAME(testGroup, testName) testGroup##testName##Class
#define TEST_CLASS_REGISTER_CLASS_NAME(testGroup, testName) testGroup##testName##ClassRegister

#define TEST(testGroup, testName) \
class TEST_CLASS_NAME(testGroup, testName) : public ETestClass {	\
public:	\
	virtual void run();	\
};	\
class TEST_CLASS_REGISTER_CLASS_NAME(testGroup, testName) {	\
public:	\
	TEST_CLASS_REGISTER_CLASS_NAME(testGroup, testName)() {	\
		TEST_CLASS_NAME(testGroup, testName) *test = new TEST_CLASS_NAME(testGroup, testName);\
		TestCaseManager::getInstance().regist(#testGroup, test);\
	}	\
};	\
TEST_CLASS_REGISTER_CLASS_NAME(testGroup, testName) testGroup##testName##RegisterIns;	\
void TEST_CLASS_NAME(testGroup, testName)::run()


#endif /* end of include guard: ETESTDEFINE_H_HULND5UB */
