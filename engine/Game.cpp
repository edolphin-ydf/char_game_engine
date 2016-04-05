#include "Game.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"

namespace edolphin {

void Game::init() {
	painter->init();
}

void Game::destory() {
	painter->destory();
	AutoReleasePoolManager::deleteInstance();
}

void Game::main() {
	init();

	while(!finished) {
		draw();	
		AutoReleasePoolManager::getInstance()->getCurrentPool()->release();
	}
}

void Game::draw() {

}

}	//edolphin
