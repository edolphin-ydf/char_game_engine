#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include "ArcObject.h"

using namespace edolphin;
using namespace std;

struct Test {
	int a;
};

struct Free {
	void operator() (void * data) {
		printf("%s\n", "in Free()");
		memset(data, 0, sizeof(Test));
		free(data);
	}
};

Test* test() {
	Test*obj = new Test;
	obj->a = 123;
	std::unique_ptr<Test, Free> ptr = std::unique_ptr<Test, Free>(obj);
	return obj;	
}

int main(int argc, char *argv[])
{
	Test *obj1 = test();
	obj1->a = 2;
	printf("%d\n", obj1->a);
	return 0;
}
