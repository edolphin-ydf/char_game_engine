#include "Game.h"
#include "AutoReleasePoolManager.h"
#include "AutoReleasePool.h"
#include "Scene.h"
#include "PainterCursor.h"
#include "TimerManager.h"
#include "Utils.h"

#include <unistd.h>
#include <stdio.h>

namespace edolphin {

Game::Game() {
	_scene = ArcObject::createObject<Scene>();
	_painter = new PainterCursor();
}

Game::~Game() {
	delete _painter;
}

bool Game::init() {
	if (!_painter->init())
		return false;
	return true;
}

void Game::destory() {
	_painter->destory();
	_scene->release();
	AutoReleasePoolManager::deleteInstance();
}

void Game::main() {
	init();

	int count = 0;
	unsigned long lastRefreshTime = Utils::getTimeStamp();
	char txt[20] = {0};
	while(!finished) {
		draw();	
		AutoReleasePoolManager::getInstance()->getCurrentPool()->release();

		unsigned long cur = Utils::getTimeStamp();
		if (cur != lastRefreshTime) {
			snprintf(txt, sizeof(txt)-1, "fps: %d/s", count);
			count = 0;
			lastRefreshTime = cur;
		}

		Millsecond nowMs = Utils::getMillionTimeStamp();
		TimerManager::getInstance()->onTimer(nowMs);

		_painter->drawText(Point2D(50, 50), txt);

		_painter->refresh();

		count++;
	}
}

void Game::draw() {
	_scene->draw();
}

}	//edolphin
