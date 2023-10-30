#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
	struct WrongFormNameException : public std::exception
	{
		const char *what() const throw()
		{
			return "Intern couldn't create the form because that type doesn't exist!";
		}
	};

public:
	Intern();
	Intern(const Intern &i);
	~Intern();
	Intern &operator=(const Intern &i);

	AForm *makeForm(std::string name, std::string target);
};

#endif