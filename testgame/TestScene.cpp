#include "TestScene.h"
#include "Picture.h"
#include "PicLoader.h"
#include "Game.h"
#include "PainterDelegate.h"
#include "GameObject.h"
#include "Action.h"
#include "Timer.h"

namespace edolphin
{
	

TestScene::TestScene() {
	(new Timer(5000, true, [this](Timer* timer, Millsecond now) {this->generateNewTanc();}))->autoRelease();
}

void TestScene::generateNewTanc() {
	Picture *testPic = PicLoader::load("/home/edolphin/documents/cpp/char_game_engine/testgame/res/test_pic.pic");
	PicObject* testPicObj = new PicObject(testPic);
	this->addObject(testPicObj);
	testPic->release();

	ActionMoveTo* move1 = new ActionMoveTo(testPicObj, Point2D(50, 50), 1500);
	ActionMoveTo* move2 = new ActionMoveTo(testPicObj, Point2D(150, 30), 1500);
	ActionMoveTo* move3 = new ActionMoveTo(testPicObj, Point2D(0, 0), 1500);
	ActionSequence* moveSeq = new ActionSequence(true);
	moveSeq->addAction(move1)->addAction(move2)->addAction(move3);
	moveSeq->start();
}

TestScene::~TestScene() {
}

void TestScene::draw() {
	Scene::draw();

	//if (testPic != nullptr) {
		//Game::getInstance()->getPainter()->drawPicture(Point2D(0, 0), testPic);
	//}
}

} /* edolphin */ 
