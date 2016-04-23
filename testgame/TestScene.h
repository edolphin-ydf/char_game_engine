#ifndef TESTSCENE_H_ZCPE0FZA
#define TESTSCENE_H_ZCPE0FZA

#include "Scene.h"
namespace edolphin
{
	

class Picture;
class TestScene : public Scene
{
public:
	TestScene ();
	virtual ~TestScene ();

	virtual void draw();

private:
	void generateNewTanc();
};
} /* edolphin */ 

#endif /* end of include guard: TESTSCENE_H_ZCPE0FZA */
