#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name),
																_signGrade(signGrade),
																_executeGrade(executeGrade)
{
	_isSigned = false;

	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();

	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &f) : _name(f._name),
							_signGrade(f._signGrade),
							_executeGrade(f._executeGrade)
{
	*this = f;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &f)
{
	_isSigned = f._isSigned;
	return *this;
}

std::string Form::getName()
{
	return _name;
}

int Form::getSignGrade()
{
	return _signGrade;
}

int Form::getExecuteGrade()
{
	return _executeGrade;
}

bool Form::isSigned()
{
	return _isSigned;
}

void Form::beSigned(Bureaucrat &b)
{
	if (_isSigned)
		return;

	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();

	_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
	o << (f.isSigned() ? "signed '" : "unsigned '") << f.getName() << "' form\n";
	o << "\trequired grade to sign: " << f.getSignGrade() << "\n";
	o << "\trequired grade to execute: " << f.getExecuteGrade();
	return o;
}