#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f) : AForm(f)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	AForm::operator=(f);
	return *this;
}

void RobotomyRequestForm::execute_concrete(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << "drrrrrrrddrdrrr\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << "The robotomy has failed on " << _target << "\n";
}