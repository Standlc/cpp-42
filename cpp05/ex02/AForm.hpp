#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	std::string _target;
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

	struct FormNotSignedExecption : public std::exception
	{
		const char *what() const throw()
		{
			return "the form is not signed yet!!";
		}
	};

public:
	AForm(std::string name, int signGrade, int executeGrade, std::string target);
	AForm(const AForm &f);
	virtual ~AForm();
	AForm &operator=(const AForm &f);

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	std::string getTarget() const;

	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void execute_concrete(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &f);

#endif