#ifndef BASETYPE_H_2ZCARIIQ
#define BASETYPE_H_2ZCARIIQ

#include "math.h"

typedef unsigned int DWORD;
typedef unsigned long QWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned long Millsecond;

#define x2(x) ((x) * (x))

template<class T>
struct BasePoint2D {
	BasePoint2D() {}
	BasePoint2D(T _x, T _y): x(_x), y(_y){}
	T x;
	T y;

	BasePoint2D operator + (BasePoint2D b) {
		return BasePoint2D(x + b.x, y + b.y);
	}
	
	BasePoint2D operator - (BasePoint2D b) {
		return BasePoint2D(x - b.x, y - b.y);
	}

	float distance(BasePoint2D b) {
		return sqrt(x2(b.x - x) + x2(b.y - y));
	}
};

template<class T>
struct BaseSize {
	BaseSize() {}
	BaseSize(T _width, T _height): width(_width), height(_height){}
	T width;
	T height;

	//BaseSize operator + (BaseSize b) {
		//return BaseSize(width + b.width, height + b.height);
	//}
	
	//BaseSize operator - (BaseSize b) {
		//return BaseSize(width - b.width, height - b.height);
	//}
};

typedef BasePoint2D<int> Point2D; 
typedef BasePoint2D<float> Point2DF;

typedef BaseSize<int> Size;

#endif /* end of include guard: BASETYPE_H_2ZCARIIQ */
