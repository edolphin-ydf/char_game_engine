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

	GeterAssign(BYTE*, data, Data);

	void setData(BYTE* data) {
		SafeDeleteS(data);
		this->data = data;
	}

	SeterGeterAssign(DWORD, width, Width);
	SeterGeterAssign(DWORD, height, Height);
	
private:
	/* data */
	BYTE* data = nullptr;	
	DWORD width = 0;
	DWORD height = 0;
};

class Test : public Drawable {
public:
	Test() {}
	~Test() {}

	void draw() {}
};

}	// ns edolphin

#endif /* end of include guard: PICTURE_H_YV56DUXM */
