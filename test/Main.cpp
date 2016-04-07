#include <stdio.h>

#include "ETestDefine.h"

TEST(testGroup, test) {
	printf("in test\n");
}

int main(int argc, char *argv[])
{
	ETest test;
	test.run();
	return 0;
}
