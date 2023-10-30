#include "Bureaucrat.hpp"

int main()
{
	// OUT OF RANGE: TOO HIGH
	try
	{
		Form form("applications", -1, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";

	// OUT OF RANGE: TOO LOW
	try
	{
		Form form("applications", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";

	// OK
	try
	{
		Form form("applications", 2, 1);
		Bureaucrat james("James", 3);

		james.signForm(form);
		std::cout << "\n";

		james.promote();
		james.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}