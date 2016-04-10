#include "ETestDefine.h"
#include "BaseType.h"

TEST(basePoint, plus) {
	Point2D pa(1, 2);
	Point2D pb(3, 4);

	Point2D pc = pa + pb;
	Assert::assertEqual(pc.x, 4);
	Assert::assertEqual(pc.y, 6);

	Point2D pd = pa - pb;
	Assert::assertEqual(pd.x, -2);
	Assert::assertEqual(pd.y, -2);
}
