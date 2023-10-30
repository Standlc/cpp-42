#include "Bureaucrat.hpp"

int main()
{
	// GRADE TOO HIGH
	try
	{
		Bureaucrat tooHighBureaucrate("John", -1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	// GRADE TOO LOW
	try
	{
		Bureaucrat tooLowBureaucrate("John", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	// OK BUREAUCRAT
	try
	{
		Bureaucrat john("John", 2);
		std::cout << john << "\n";

		john.promote();
		std::cout << john << "\n";

		john.promote();
		std::cout << john << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}