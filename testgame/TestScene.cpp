#include "TestScene.h"
#include "Picture.h"
#include "PicLoader.h"
#include "Game.h"
#include "PainterDelegate.h"
#include "GameObject.h"
#include "Action.h"
#include "Timer.h"
#include "KeyboardEventDispatcher.h"

namespace edolphin
{
	

TestScene::TestScene() {
	//(new Timer(1000, true, [this](Timer* timer, Millsecond now) {this->generateNewTanc();}))->autoRelease();
	generateNewTanc();
	KeyboardEventDispatcher::getInstance()->regist(this);
}

void TestScene::generateNewTanc() {
	Picture *testPic = PicLoader::load("/home/edolphin/documents/cpp/char_game_engine/testgame/res/test_pic.pic");
	PicObject* testPicObj = new PicObject(testPic);
	this->addObject(testPicObj);
	testPic->release();

	ActionMoveTo* move1 = new ActionMoveTo(testPicObj, Point2D(50, 50), 500);
	ActionMoveTo* move2 = new ActionMoveTo(testPicObj, Point2D(150, 30), 500);
	ActionMoveTo* move3 = new ActionMoveTo(testPicObj, Point2D(0, 0), 500);
	moveSeq = new ActionSequence(true);
	moveSeq->addAction(move1)->addAction(move2)->addAction(move3);
	moveSeq->start();
}

TestScene::~TestScene() {
}

void TestScene::draw() {
	Scene::draw();
}

void TestScene::onKeyPressed(char key) {
	if (key == 's') {
		moveSeq->stop();	
	} else if (key == 'r') {
		moveSeq->resume();	
	} else if (key == 'p') {
		moveSeq->pause();
	} else if (key == 't') {
		moveSeq->restart();
	} else if (key == 'a') {
		moveSeq->start();
	}
}


} /* edolphin */ 

