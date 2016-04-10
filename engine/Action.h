#ifndef ACTION_H_M9DNOUJS
#define ACTION_H_M9DNOUJS

#include "Drawable.h"
#include "GetterSetter.h"

namespace edolphin {


class Action
{
public:
	Action ();
	virtual ~Action ();

	virtual void action() = 0;

	SetterGetter<Drawable*> owner = SetterGetter<Drawable*>(_owner);

protected:
	/* data */
	Drawable *_owner;
};

}

#endif /* end of include guard: ACTION_H_M9DNOUJS */
