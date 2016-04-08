#ifndef TESTCASEMANAGER_H_3VNV92LB
#define TESTCASEMANAGER_H_3VNV92LB

#include <map>
#include <list>
#include <functional>
#include <string>
#include "ETestClass.h"

class TestCaseManager
{
	typedef std::list<ETestClass*> TestGroup;
	typedef TestGroup::iterator TestGroup_IT;
	typedef std::map<std::string, TestGroup > TestMap;
	typedef TestMap::iterator TestMap_IT;

public:
	static TestCaseManager& getInstance();
	static void deleteInstance();

	void regist(std::string group, ETestClass* test);

	void run();

	void foreach(std::function<void(ETestClass*)> callback);

	TestMap getTests() {return tests;}

public:
	std::string errMsg = "";
	bool hasError = false;

private:
	TestCaseManager () {};
	virtual ~TestCaseManager () {};

private:
	/* data */

	TestMap tests;

	static TestCaseManager *inst;
};

#endif /* end of include guard: TESTCASEMANAGER_H_3VNV92LB */
