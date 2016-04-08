#include "ETest.h"
#include "TestCaseManager.h"

void ETest::beforeTest() {

}

void ETest::afterTest() {

}

void ETest::run() {
	beforeTest();
	TestCaseManager::getInstance().run();
	afterTest();
}
