#include "GetterSetter.h"
#include "ETestDefine.h"

using namespace edolphin;

class GetterSetterTestClass {
public:

	int _x = 1;
	
	Getter<int> getX = Getter<int>(_x);
	Setter<int> setX = Setter<int>(_x);
	SetterGetter<int> x = SetterGetter<int>(_x);

	int *_y = &_x;

	SetterGetter<int*> y = SetterGetter<int*>(_y);
	Getter<int*> getY = Getter<int*>(_y);
	Setter<int*> setY = Setter<int*>(_y);
};

#include <stdio.h>

TEST(GetterSetter, notPointer) {
	GetterSetterTestClass t;
	Assert::assertEqual(t.getX(), t._x);
	Assert::assertEqual(&(t.getX()), &(t._x));
}

TEST(GetterSetter, pointer) {
	GetterSetterTestClass t;
	Assert::assertEqual(t.getY(), t._y);
	Assert::assertEqual(&(t.getY()), &(t._y));
	Assert::assertEqual(*(t.getY()), *(t._y));
}
