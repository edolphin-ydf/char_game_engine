#ifndef PICTURE_H_YV56DUXM
#define PICTURE_H_YV56DUXM

#include "BaseType.h"
#include "ArcObject.h"
#include "GetterSetter.h"

namespace edolphin {

class Picture : public ArcObject
{
public:
	Picture ();
	Picture(BYTE* data, DWORD width, DWORD height);
	virtual ~Picture ();

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


}	// ns edolphin

#endif /* end of include guard: PICTURE_H_YV56DUXM */
