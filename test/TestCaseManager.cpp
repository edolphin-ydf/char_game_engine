#include "TestCaseManager.h"

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
	foreach([](ETestClass* test) {test->run();});
}

void TestCaseManager::foreach(std::function<void(ETestClass*)> callback) {
	for (auto it_group : tests) {
		for (auto it_test : it_group.second) {
			callback(it_test);
		}	
	}
}
