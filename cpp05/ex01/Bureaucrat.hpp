#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return "The grade is too high";
		}
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return "The grade is too low";
		}
	};

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &b);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &b);

	int getGrade();
	std::string getName();
	void promote();
	void downgrade();

	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif