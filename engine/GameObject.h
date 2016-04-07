#ifndef GAMEOBJECT_H_QMWBXJZZ
#define GAMEOBJECT_H_QMWBXJZZ

#include "ArcObject.h"
#include "Drawable.h"

namespace edolphin {

class GameObject : public ArcObject, public Drawable
{
public:
	GameObject ();
	virtual ~GameObject ();

	virtual void draw() = 0;

private:
	/* data */

};

}

#endif /* end of include guard: GAMEOBJECT_H_QMWBXJZZ */

