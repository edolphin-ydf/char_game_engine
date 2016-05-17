#ifndef BASETYPE_H_2ZCARIIQ
#define BASETYPE_H_2ZCARIIQ

#include <math.h>

typedef unsigned int DWORD;
typedef unsigned long QWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned long Millsecond;

#define x2(x) ((x) * (x))
//#define abs(x) ( (x) > 0? (x): -(x))

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

template<class T>
struct BaseRect {
	BaseRect() {}
	BaseRect(BasePoint2D<T> _position, BaseSize<T> _size): position(_position), size(_size) {}
	BasePoint2D<T> position;
	BaseSize<T> size;

	BasePoint2D<T> getlu() {
		return position;
	}

	BasePoint2D<T> getld() {
		return BasePoint2D<T>(position.x, position.y + size.height);
	}

	BasePoint2D<T> getru() {
		return BasePoint2D<T>(position.x + size.width, position.y);
	}

	BasePoint2D<T> getrd() {
		return BasePoint2D<T>(position.x + size.width, position.y + size.height);
	}

	BasePoint2D<T> getCenter() {
		return BasePoint2D<T>(position.x + size.width / 2.0, position.y + size.height / 2.0);
	}
};

template<class T, class R>
struct BaseCircle {
	BaseCircle() {}
	BaseCircle(BasePoint2D<T> _center, R _r) : center(_center), r(_r){}
	
	BasePoint2D<T> center;
	R r;
};

typedef BasePoint2D<int> Point2D; 
typedef BasePoint2D<float> Point2DF;

typedef BaseSize<int> Size;

typedef BaseRect<int> Rect;

typedef BaseCircle<int, double> Circle;

#endif /* end of include guard: BASETYPE_H_2ZCARIIQ */




