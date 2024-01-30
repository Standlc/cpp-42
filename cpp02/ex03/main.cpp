#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

bool isPoint(Point const point, int x, int y)
{
	return x == roundf(point.getX().toFloat()) && y == roundf(point.getY().toFloat());
}

void printTriangle(Point const a, Point const b, Point const c, Point const point)
{
	for (int y = 10; y >= 0; y--)
	{
		for (int x = 0; x <= 20; x++)
		{
			if (isPoint(point, x, y))
				std::cout << "X";
			else if (isPoint(a, x, y) || isPoint(b, x, y) || isPoint(c, x, y))
				std::cout << "0";
			else if (bsp(a, b, c, Point(x, y)) == true)
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
	{
		std::cerr << "./bsp <x> <y>" << std::endl;
		return (1);
	}

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