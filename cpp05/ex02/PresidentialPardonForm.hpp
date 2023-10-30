#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &f);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &f);

	void execute_concrete(Bureaucrat const &executor) const;
};

#endif