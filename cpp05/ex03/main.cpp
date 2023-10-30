#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(NULL));
	Bureaucrat james("James", 1);
	Intern intern;
	AForm *form = NULL;

	// WRONG FORM NAME
	try
	{
		form = intern.makeForm("wrong name", "wrong_target");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try
	{
		// PRESIDENTIAL PARDON
		form = intern.makeForm("presidential pardon", "presidential_pardon_target");
		std::cout << "\n";

		james.signForm(*form);
		std::cout << "\n";
		james.executeForm(*form);
		std::cout << "\n";
		delete form;

		// ROBOTOMY REQUEST
		form = intern.makeForm("robotomy request", "robotomy_target");
		std::cout << "\n";

		james.signForm(*form);
		std::cout << "\n";
		james.executeForm(*form);
		std::cout << "\n";
		delete form;

		// SHRUBBERY CREATION
		form = intern.makeForm("shrubbery creation", "shrubbery");
		std::cout << "\n";

		james.signForm(*form);
		std::cout << "\n";
		james.executeForm(*form);
		std::cout << "\n";
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}