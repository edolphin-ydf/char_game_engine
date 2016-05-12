#include "KeyboardEventLogger.h"
#include "Game.h"
#include "Logger.h"

namespace edolphin
{
	

void KeyboardEventLogger::onKeyPressed(char key) {
	Game::getInstance()->getLogger()->debug("%c", key);
}

} /* edolphin */ 
