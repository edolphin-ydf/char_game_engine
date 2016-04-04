#include "Game.h"

void Game::main() {
	init();

	while(!finished) {
		draw();	
	}
}

