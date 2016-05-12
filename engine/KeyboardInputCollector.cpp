#include "KeyboardInputCollector.h"
#include "Game.h"
#include "KeyboardBuffer.h"
#include "curses.h"

namespace edolphin
{


KeyboardInputCollector::KeyboardInputCollector() {
}	

KeyboardInputCollector::~KeyboardInputCollector() {

}

void KeyboardInputCollector::run() {
	collectThread = std::thread(&KeyboardInputCollector::collect, this);
}

void KeyboardInputCollector::collect() {
	while(!finished) {
		char key = getch();
		Game::getInstance()->getKeyboardBuffer()->push(key);
	}
}

void KeyboardInputCollector::final() {
	finished = true;

	collectThread.join();
}

} /* edolphin */ 
