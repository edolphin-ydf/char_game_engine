#include "Assert.h"
#include "TestCaseManager.h"

void Assert::assertFail(const char* msg) {
	TestCaseManager::getInstance().errMsg = msg;
	TestCaseManager::getInstance().hasError = true;
}

void Assert::assertTrue(bool val) {
	if (!val)
		assertFail("assert true fail");
}
