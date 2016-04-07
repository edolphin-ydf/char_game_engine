#include "Color.h"

namespace edolphin {

Color Color::black = Color(0, 0, 0);
Color Color::red = Color(255, 0, 0);
Color Color::green = Color(0, 255, 0);
Color Color::blue = Color(0, 0, 255);
Color Color::white = Color(255, 255, 255);

Color::Color(int _ar, int _ag, int _ab) {
	_r = _ar;
	_g = _ag;
	_b = _ab;
}
}
