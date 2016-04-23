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
