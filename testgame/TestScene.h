#ifndef TESTSCENE_H_ZCPE0FZA
#define TESTSCENE_H_ZCPE0FZA

#include "Scene.h"
#include "KeyboardEventListener.h"
#include <vector>

namespace edolphin
{
	
class TankRobot;
class Picture;
class ActionSequence;
class MainCharacter;
class TestScene : public Scene, public KeyboardEventListener
{
public:
	TestScene ();
	virtual ~TestScene ();

	virtual void draw();

	virtual void onKeyPressed(char key);

	void addTankRobot(TankRobot* tr);
	void removeTankRobot(TankRobot* tr);

private:
	void generateNewTanc();

	ActionSequence* moveSeq;

	MainCharacter* mc;

	std::vector<TankRobot*> tankRobots;
};

} /* edolphin */ 

#endif /* end of include guard: TESTSCENE_H_ZCPE0FZA */
