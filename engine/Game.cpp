#include "Game.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"
#include "Scene.h"
#include "PainterCursor.h"
#include "TimerManager.h"
#include "Utils.h"
#include "Logger.h"
#include "KeyboardEventDispatcher.h"
#include "KeyboardInputCollector.h"
#include "KeyboardBuffer.h"

#include <unistd.h>
#include <stdio.h>

namespace edolphin {

Logger* Game::logger = nullptr;

Game::Game() {
	_painter = new PainterCursor();
	keyboardBuffer = new KeyboardBuffer();
	keyboardInputCollector = new KeyboardInputCollector();
}

Game::~Game() {
	delete _painter;
	delete keyboardBuffer;
	delete keyboardInputCollector;
}

bool Game::init() {
	if (!_painter->init())
		return false;
	keyboardInputCollector->run();
	return true;
}

void Game::destory() {
	_painter->destory();
	SafeRelease(_scene);
	AutoReleasePoolManager::deleteInstance();
}

void Game::main() {
	init();

	int count = 0;
	unsigned long lastRefreshTime = Utils::getTimeStamp();
	char txt[20] = {0};
	while(!finished) {
		_painter->clean();
		draw();	
		AutoReleasePoolManager::getInstance()->getCurrentPool()->release();

		// keyboard event dispatch
		char key = keyboardBuffer->pop();
		while(key != 0) {
			KeyboardEventDispatcher::getInstance()->onKeyPressed(key);
			key = keyboardBuffer->pop();
		}

		// fps
		unsigned long cur = Utils::getTimeStamp();
		if (cur != lastRefreshTime) {
			snprintf(txt, sizeof(txt)-1, "fps: %d/s", count);
			count = 0;
			lastRefreshTime = cur;
		}
		_painter->drawText(Point2D(50, 50), txt);

		// timer
		Millsecond nowMs = Utils::getMillionTimeStamp();
		TimerManager::getInstance()->onTimer(nowMs);

		_painter->refresh();

		count++;
	}
}

void Game::draw() {
	if (_scene != nullptr) {
		_scene->draw();
	}
}

Logger* Game::getLogger() {
	if (logger == nullptr) {
		logger = new Logger("./Game.log");
	}
	return logger;
}


}	//edolphin
