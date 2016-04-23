#ifndef GAMEOBJECT_H_QMWBXJZZ
#define GAMEOBJECT_H_QMWBXJZZ

#include "Drawable.h"

namespace edolphin {

class Picture;
class PicObject : public Drawable
{
public:
	PicObject(const char* path);
	PicObject (Picture* picture);
	virtual ~PicObject ();

	virtual void draw();
private:
	Picture* pic;
};

}

#endif /* end of include guard: GAMEOBJECT_H_QMWBXJZZ */

