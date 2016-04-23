#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include "ArcObject.h"
#include "Game.h"
#include "Scene.h"
#include "Timer.h"
#include "TestScene.h"
#include <Utils.h>

using namespace edolphin;
using namespace std;

void initScene() {
	Timer *timer = new Timer(1000, true, [](Timer* timer, Millsecond now) { 
			char txt[20] = {0};
			snprintf(txt, sizeof(txt) -1, "now:%lu", now);
			Game::getInstance()->getPainter()->drawText(Point2D(0, 0), txt);
		});
	timer->release();

	TestScene* testScene = ArcObject::createObject<TestScene>();
	Game::getInstance()->setScene(testScene);

}

int main(int argc, char *argv[])
{
	printf("%ld %ld\n", Utils::getMillionTimeStamp(), Utils::getTimeStamp());
	initScene();
	Game::getInstance()->main();
	return 0;
}
