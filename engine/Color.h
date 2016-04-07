#ifndef COLOR_H_ATZPVOWX
#define COLOR_H_ATZPVOWX

#include "GetterSetter.h"

namespace edolphin {

class Color
{
public:
	Color (int _ar, int _ag, int _ab);
	virtual ~Color ();

	SetterGetter<int> r = SetterGetter<int>(_r);
	SetterGetter<int> g = SetterGetter<int>(_g);
	SetterGetter<int> b = SetterGetter<int>(_b);

	void operator = (Color aColor) {
		_r = aColor.r();
		_g = aColor.g();
		_b = aColor.b();
	}

public:
	static Color black;
	static Color red;
	static Color green;
	static Color blue;
	static Color white;

private:
	/* data */
	int _r, _g, _b;
};

}

#endif /* end of include guard: COLOR_H_ATZPVOWX */
