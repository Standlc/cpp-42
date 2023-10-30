#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &i)
{
	(void)i;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &i)
{
	(void)i;
	return *this;
}

AForm *createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }

AForm *createPresidential(std::string target) { return new PresidentialPardonForm(target); }

AForm *createRobotomy(std::string target) { return new RobotomyRequestForm(target); }

AForm *Intern::makeForm(std::string name, std::string target)
{
	static std::string formNames[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	static AForm *(*formsFunctions[])(std::string) = {createShrubbery, createPresidential, createRobotomy};

	int index = 0;
	while (index < 3 && name != formNames[index])
		index++;

	if (index >= 3)
		throw WrongFormNameException();

	AForm *formPtr = formsFunctions[index](target);
	std::cout << "Intern creates: " << *formPtr << "\n";
	return formPtr;
}
