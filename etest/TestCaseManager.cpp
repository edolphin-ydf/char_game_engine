#include "TestCaseManager.h"
#include "AssertException.h"

#define RED "\033[1;31;40m"
#define GREEN "\033[1;32;40m"
#define DEFAULT "\033[0m"

TestCaseManager* TestCaseManager::inst = nullptr;

TestCaseManager& TestCaseManager::getInstance() {
	if (inst == nullptr) {
		inst = new TestCaseManager();
	}
	return *inst;
}

void TestCaseManager::deleteInstance() {
	if (inst != nullptr) {
		delete inst;
		inst = nullptr;
	}
}

void TestCaseManager::regist(std::string group, ETestClass* test) {
	TestMap_IT it_group = tests.find(group);
	std::list<ETestClass*> testGroup;
	if (it_group == tests.end()) {
		std::list<ETestClass*> testGroup;
		testGroup.push_back(test);
		tests.insert(std::make_pair(group, testGroup));
	} else {
		it_group->second.push_back(test);
	}
}

void TestCaseManager::run() {
	foreach([this](ETestClass* test) {
		hasError = false;
		test->run();
		if (!hasError && showResult) {
			printf(GREEN "[PASS]" DEFAULT " %s %s\n", test->getGroupName().c_str(), test->getTestName().c_str());
		} else if (hasError){
			printf(RED "[FAIL]" DEFAULT " %s %s %s\n", test->getGroupName().c_str(), test->getTestName().c_str(), errMsg.c_str());
		}
	});
}

void TestCaseManager::foreach(std::function<void(ETestClass*)> callback) {
	for (auto it_group : tests) {
		for (auto it_test : it_group.second) {
			callback(it_test);
		}	
	}
}
