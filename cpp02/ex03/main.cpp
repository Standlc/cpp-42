#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

bool isPoint(Point const point, int x, int y)
{
	return x == std::roundf(point.getX().toFloat()) && y == std::roundf(point.getY().toFloat());
}

void printTriangle(Point const a, Point const b, Point const c, Point const point)
{
	for (int i = 15; i >= -1; i--)
	{
		for (int j = 0; j < 30; j++)
		{
			if (isPoint(point, j, i))
				std::cout << "x";
			else if (isPoint(a, j, i) || isPoint(b, j, i) || isPoint(c, j, i))
				std::cout << "o";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);

	Point a(0, 0);
	Point b(10, 10);
	Point c(20, 0);
	Point point(atoi(argv[1]), atoi(argv[2]));

	printTriangle(a, b, c, point);

	if (bsp(a, b, c, point) == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return 0;
}