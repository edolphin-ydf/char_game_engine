#include "Game.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"

#include <curses.h>

namespace edolphin {

void Game::init() {
	initscr();	
	if (has_colors()) {
		showColor = true;
	}
	use_default_colors();
	noecho();
}

void Game::destory() {
	endwin();
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
