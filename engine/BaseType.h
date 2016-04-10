#ifndef BASETYPE_H_2ZCARIIQ
#define BASETYPE_H_2ZCARIIQ


typedef unsigned int DWORD;
typedef unsigned long QWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

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
};

typedef BasePoint2D<int> Point2D; 
typedef BasePoint2D<float> Point2DF;


#endif /* end of include guard: BASETYPE_H_2ZCARIIQ */
