#include "Fixed.hpp"

// int main(void)
// {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return 0;
// }

int main(void)
{
	Fixed a(10);
	Fixed b(15);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;

	std::cout << "\ncomparisons\n";
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;

	std::cout << "\nincrements\n";
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++b: " << ++b << std::endl;
	std::cout << "b++: " << b++ << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	return 0;
}
