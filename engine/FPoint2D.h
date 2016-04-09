#ifndef FPOINT2D_H_HNYM5WLC
#define FPOINT2D_H_HNYM5WLC

namespace edolphin{

class FPoint2D
{
public:
	FPoint2D (float _x, float _y)
		:x(_x), y(_y)
	{}

	virtual ~FPoint2D (){};

private:
	/* data */
	float x;
	float y;
};

}	// namespace edolphin

#endif /* end of include guard: FPOINT2D_H_HNYM5WLC */
