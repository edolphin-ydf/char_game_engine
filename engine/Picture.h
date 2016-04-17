#ifndef PICTURE_H_YV56DUXM
#define PICTURE_H_YV56DUXM

#include "BaseType.h"
#include "GetterSetter.h"
#include "Drawable.h"

namespace edolphin {

class Picture : public Drawable
{
public:
	Picture ();
	Picture(BYTE* data, DWORD width, DWORD height);
	virtual ~Picture ();

	virtual void draw();

	SetterGetter<DWORD> width = SetterGetter<DWORD>(_width);
	SetterGetter<DWORD> height = SetterGetter<DWORD>(_height);
	SetterGetter<BYTE*> data = SetterGetter<BYTE*>(_data);

private:
	/* data */
	BYTE* _data = nullptr;	
	DWORD _width = 0;
	DWORD _height = 0;
};

}	// ns edolphin

#endif /* end of include guard: PICTURE_H_YV56DUXM */
