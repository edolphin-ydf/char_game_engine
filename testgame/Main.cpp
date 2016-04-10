#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include "ArcObject.h"
#include "Game.h"
#include "Scene.h"
#include "Line.h"

using namespace edolphin;
using namespace std;

void initScene() {
	Scene* scene = Game::getInstance()->getScene();
	Line* line = new Line(10, 10, 30, 20);
	scene->addObject(line);
	line->autoRelease();
}

int main(int argc, char *argv[])
{
	initScene();
	Game::getInstance()->main();
	return 0;
}
