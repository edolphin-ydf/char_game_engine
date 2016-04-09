#include <stdio.h>
#include "ETest.h"
#include "PainterCursor.h"
#include "TestCaseManager.h"


int main(int argc, char *argv[])
{
	ETest test;
	TestCaseManager::getInstance().showResult = false;
	test.run();
	return 0;
}


