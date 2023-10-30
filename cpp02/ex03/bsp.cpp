#include "Point.hpp"

static Fixed absolute(Fixed x)
{
	if (x < 0)
		return x * -1;
	return x;
}

static Fixed triangleArea(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY())) +
			 (b.getX() * (c.getY() - a.getY())) +
			 (c.getX() * (a.getY() - b.getY()))) /
			2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = absolute(triangleArea(a, b, c));
	Fixed pabArea = absolute(triangleArea(point, a, b));
	Fixed pbcArea = absolute(triangleArea(point, b, c));
	Fixed pcaArea = absolute(triangleArea(point, c, a));

	if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
		return (false);
	return (abcArea == pabArea + pbcArea + pcaArea);
}