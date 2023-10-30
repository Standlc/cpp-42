#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}

// int main(void)
// {
// 	Fixed a(10);
// 	Fixed b(15);

// 	// std::string str1 = "hello";
// 	// std::string str2 = " world";
// 	// std::cout << "assigning: " << &(str1 = str2) << "\n";
// 	// std::cout << "assigning: " << &str1 << "\n";

// 	// Fixed const b(Fixed(5.05f) * Fixed(2));
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << a + b << std::endl;
// 	std::cout << a - b << std::endl;
// 	std::cout << a * b << std::endl;
// 	std::cout << a / b << std::endl;

// 	std::cout << "comparisons\n";
// 	std::cout << (a > b) << std::endl;
// 	std::cout << (a < b) << std::endl;
// 	std::cout << (a >= b) << std::endl;
// 	std::cout << (a <= b) << std::endl;

// 	std::cout << ++a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << b++ << std::endl;
// 	std::cout << b++ << std::endl;

// 	std::cout << Fixed::max(a, b) << std::endl;
// 	std::cout << Fixed::min(a, b) << std::endl;
// 	return 0;
// }
