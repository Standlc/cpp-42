#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		_grade = 1;
		throw GradeTooHighException();
	}

	if (grade > 150)
	{
		_grade = 150;
		throw GradeTooLowException();
	}

	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b._name)
{
	*this = b;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	_grade = b._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName()
{
	return _name;
}

void Bureaucrat::promote()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::downgrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << ", signed: " << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << *this << ", couldn't sign: " << f
				  << "\nbecause: " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute_concrete(*this);
		std::cout << *this << ", executed: " << form << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << *this << ", couldn't execute: " << form
				  << "\nbecause " << e.what() << "\n";
	}
}