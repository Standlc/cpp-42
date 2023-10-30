#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return "bureaucrat's grade is too low!!";
		}
	};

	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return "bureaucrat's grade is too high!!";
		}
	};

public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &f);
	~Form();
	Form &operator=(const Form &f);

	std::string getName();
	int getSignGrade();
	int getExecuteGrade();
	bool isSigned();

	void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif