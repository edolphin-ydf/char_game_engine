#ifndef TESTSCENE_H_ZCPE0FZA
#define TESTSCENE_H_ZCPE0FZA

#include "Scene.h"
#include "KeyboardEventListener.h"

namespace edolphin
{
	

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

private:
	void generateNewTanc();

	ActionSequence* moveSeq;

	MainCharacter* mc;
};

} /* edolphin */ 

#endif /* end of include guard: TESTSCENE_H_ZCPE0FZA */
