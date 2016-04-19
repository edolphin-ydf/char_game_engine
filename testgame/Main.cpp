#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include "ArcObject.h"
#include "Game.h"
#include "Scene.h"

using namespace edolphin;
using namespace std;

void initScene() {
}

int main(int argc, char *argv[])
{
	initScene();
	Game::getInstance()->main();
	return 0;
}
