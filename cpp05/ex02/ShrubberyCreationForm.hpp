#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &f);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &f);

	void execute_concrete(const Bureaucrat &b) const;
};

#endif