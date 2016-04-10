#ifndef TESTCASEMANAGER_H_3VNV92LB
#define TESTCASEMANAGER_H_3VNV92LB

#include <map>
#include <list>
#include <functional>
#include <string>
#include "ETestClass.h"

#define BEFORE_TEST_CLASS_NAME "beforeClass"
#define AFTER_TEST_CLASS_NAME "afterClass"

class TestCaseManager
{
	typedef std::list<ETestClass*> TestGroup;
	typedef TestGroup::iterator TestGroup_IT;
	typedef std::map<std::string, TestGroup > TestMap;
	typedef TestMap::iterator TestMap_IT;

	typedef std::map<std::string, ETestClass*> SingleTestMap;
	typedef SingleTestMap::iterator SingleTestMap_IT;

public:
	static TestCaseManager& getInstance();
	static void deleteInstance();

	void regist(std::string group, ETestClass* test);

	void run();

	void foreach(std::function<void(ETestClass*)> callback);
	void foreach(std::function<void(ETestClass*)> before, 
		std::function<void(ETestClass*)> callback, 
		std::function<void(ETestClass*)> after);

	TestMap getTests() {return tests;}

public:
	std::string errMsg = "";
	bool hasError = false;
	bool showResult = true;

private:
	TestCaseManager () {};
	virtual ~TestCaseManager () {};

private:
	/* data */

	TestMap tests;
	SingleTestMap beforeTest;
	SingleTestMap afterTest;

	static TestCaseManager *inst;
};

#endif /* end of include guard: TESTCASEMANAGER_H_3VNV92LB */
