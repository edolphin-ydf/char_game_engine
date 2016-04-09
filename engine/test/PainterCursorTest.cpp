#include "ETestDefine.h"
#include "PainterCursor.h"
#include <unistd.h>

using namespace edolphin;
PainterCursor *painterCursor = new PainterCursor();
void before() {
	if(painterCursor->init())
		printf("init painterCursor success\n");
}

void after() {
	sleep(1);
	painterCursor->destory();
}

class RegistClass {
public:
	RegistClass() {
		before();
	}
	~RegistClass() {
		after();
	}
};
RegistClass registClass;

TEST(painterCursor, point) {
	painterCursor->drawPoint(3, 50);
	painterCursor->refresh();
	sleep(1);
}

TEST(painterCursor, line) {
	painterCursor->drawLine(Point2D(4, 4), Point2D(8, 8));
	painterCursor->refresh();
	sleep(5);
	painterCursor->drawLine(Point2D(14, 14), Point2D(25, 30));
	painterCursor->refresh();
	sleep(5);
}

TEST(painterCursor, rectangle) {
	painterCursor->drawRectangle(Point2D(4, 4), Point2D(8, 8));
	painterCursor->refresh();
	sleep(5);
	painterCursor->drawRectangle(Point2D(8, 8), Point2D(9, 10));
	painterCursor->refresh();
	sleep(5);
}

TEST(painterCursor, text) {
	painterCursor->drawText(Point2D(10, 50), "the test text");
	painterCursor->refresh();
}
