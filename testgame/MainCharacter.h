#ifndef MAINCHARACTER_H_1FU3YGNP
#define MAINCHARACTER_H_1FU3YGNP

#include "Drawable.h"
#include "KeyboardEventListener.h"

namespace edolphin
{
	

class Picture;
class MainCharacter : public Drawable, KeyboardEventListener
{
public:
	MainCharacter ();
	virtual ~MainCharacter () {};

	virtual void onKeyPressed(char key);

	virtual void draw();

	virtual void release() { Drawable::release();};
private:

	Picture* picture = nullptr;
};


} /* edolphin */ 

#endif /* end of include guard: MAINCHARACTER_H_1FU3YGNP */
