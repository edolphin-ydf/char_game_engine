#ifndef DRAWABLE_H_O14IJINU
#define DRAWABLE_H_O14IJINU

namespace edolphin {

class Drawable
{
public:
	Drawable ();
	virtual ~Drawable ();

	virtual void draw() = 0;
};

}

#endif /* end of include guard: DRAWABLE_H_O14IJINU */
