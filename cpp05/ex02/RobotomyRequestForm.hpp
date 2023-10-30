#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &f);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &f);

	void execute_concrete(Bureaucrat const &executor) const;
};

#endif