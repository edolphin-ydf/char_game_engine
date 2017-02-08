#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include "ArcObject.h"
#include "Game.h"
#include "Scene.h"
#include "Timer.h"
#include "TestScene.h"
#include "KeyboardEventDispatcher.h"
#include "KeyboardEventLogger.h"
#include <Utils.h>

using namespace edolphin;
using namespace std;

void initScene() {
	TestScene* testScene = ArcObject::createObject<TestScene>();
	Game::getInstance()->setScene(testScene);
}

void registKeyboardListener() {
	KeyboardEventDispatcher::getInstance()->regist(new KeyboardEventLogger());
}

//int main(int argc, char *argv[])
//{
	//printf("%ld %ld\n", Utils::getMillionTimeStamp(), Utils::getTimeStamp());
	//registKeyboardListener();
	//initScene();
	//Game::getInstance()->main();
	//return 0;
//}

//class a {
//public:
	//virtual void funcb(int a) {
		//printf("in a\n");
	//}
//};

//class b : virtual a {
//public:
	//virtual void funcb() {
		//printf("in b\n");
	//}
//};

//int main(int argc, char *argv[])
//{
	//printf("%ld\n", sizeof(b));
	//printf("%ld\n", sizeof(a));

	//b* bb = new b();
	//bb->funcb(1);
	//return 0;
//}

class Object {
public:
	int id;
	std::string name;
};

class Action {
public:
	virtual void doAction(Object* o) const {
		printf("in Action::doAction\n");
	}
};

class SetIdAction : public Action {
public:
	int id;
	virtual void doAction(Object* o) const {
		printf("in SetIdAction::doAction\n");
		o->id = this->id;
	}
};

class SetNameAction : public Action {
public:
	std::string name;
	virtual void doAction(Object* o) const {
		printf("in SetNameAction::doAction\n");
		o->name = this->name;
	}
};

class ActionSet : public Action {
public:
	std::vector<const Action*> actions;

	virtual void doAction(Object* o) const {
		printf("in ActionSet::doAction\n");
		for (auto action : actions) {
			action->doAction(o);
		}
		//std::for_each(actions.begin(), actions.end(), [o](const Action* a) { a->doAction(o);});
	}

	//ActionSet& operator + (const ActionSet& rhs) {
		//std::for_each(rhs.actions.begin(), rhs.actions.end(), [this](const Action* a) {this->actions.push_back(a);});
		//return *this;
	//}
};

class Package {
public:
	std::vector<Object*> objects;
	
	void forEach(const Action& act) {
		for (auto o : objects) {
			act.doAction(o);
		}
		//std::for_each(objects.begin(), objects.end(), [act](Object* o) { act.doAction(o);} );
	}
};

const ActionSet operator + (const Action& a, const Action& b) {
	ActionSet as;
	as.actions.push_back(&a);
	as.actions.push_back(&b);
	return as;
}

#define SetPropFunc(_func, _type, _prop, _act_type, _val) \
	_type set##_func##Function(_type _prop) { \
		_act_type __act;	\
		__act._prop = _val;	\
		return __act;	\
	}

SetIdAction setId(int id) {
	SetIdAction res;
	res.id = id;
	return res;
}

SetNameAction setName(std::string name) {
	SetNameAction res;
	res.name = name;
	return res;
}

//#define setId(id) (setIdFunction(id))
//#define setName(name) (setNameFunction(name))

int main(int argc, char *argv[])
{
	Package package;
	Object* o = new Object;	
	package.objects.push_back(o);

	package.forEach(setId(1) + setName("adf"));

	printf("%d %s\n", o->id, o->name.c_str());
	return 0;
}




