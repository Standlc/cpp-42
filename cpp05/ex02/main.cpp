#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	srand(time(NULL));
	Bureaucrat james("James", 3);
	Bureaucrat jack("Jack", 26);
	Bureaucrat jeff("Jeff", 150);

	try
	{
		// 25, 5
		PresidentialPardonForm pardonForm("presidential_pardon_target");

		james.signForm(pardonForm);
		std::cout << "\n";
		james.executeForm(pardonForm);
		std::cout << "\n";

		jack.executeForm(pardonForm);
		std::cout << "\n";

		// 72, 45
		RobotomyRequestForm robotomy("robotomy_target");
		jack.signForm(robotomy);
		std::cout << "\n";
		jack.executeForm(robotomy);
		std::cout << "\n";

		// 145, 137
		ShrubberyCreationForm shrubbery("shrubbery_target");
		james.signForm(shrubbery);
		std::cout << "\n";
		james.executeForm(shrubbery);
		std::cout << "\n";

		ShrubberyCreationForm shrubbery_2("shrubbery_2_target");
		jeff.executeForm(shrubbery_2);
		std::cout << "\n";
		james.signForm(shrubbery_2);
		std::cout << "\n";
		jeff.executeForm(shrubbery_2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
}