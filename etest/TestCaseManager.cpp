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
	if (test->getTestName() == BEFORE_TEST_CLASS_NAME) {
		beforeTest.insert(std::make_pair(group, test));
		return;
	}
	if (test->getTestName() == AFTER_TEST_CLASS_NAME) {
		afterTest.insert(std::make_pair(group, test));
		return;
	}

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
	std::function<void(ETestClass*)> baf = [this](ETestClass* test) { test->run(); };

	foreach(baf, [this](ETestClass* test) {
		hasError = false;
		test->run();
		if (!hasError && showResult) {
			printf(GREEN "[PASS]" DEFAULT " %s %s\n", test->getGroupName().c_str(), test->getTestName().c_str());
		} else if (hasError){
			printf(RED "[FAIL]" DEFAULT " %s %s %s\n", test->getGroupName().c_str(), test->getTestName().c_str(), errMsg.c_str());
		}
	}, baf);
}

void TestCaseManager::foreach(std::function<void(ETestClass*)> callback) {
	for (auto it_group : tests) {
		for (auto it_test : it_group.second) {
			callback(it_test);
		}	
	}
}

void TestCaseManager::foreach(std::function<void(ETestClass*)> before, 
		std::function<void(ETestClass*)> callback, 
		std::function<void(ETestClass*)> after) {
	for (auto it_group : tests) {
		SingleTestMap_IT it_before = beforeTest.find(it_group.first);
		if (it_before != beforeTest.end()) {
			before(it_before->second);
		}

		for (auto it_test : it_group.second) {
			callback(it_test);
		}	

		SingleTestMap_IT it_after = afterTest.find(it_group.first);
		if (it_after != afterTest.end()) {
			after(it_after->second);
		}
	}
}


