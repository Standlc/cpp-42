#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade, std::string target) : _name(name),
																					  _signGrade(signGrade),
																					  _executeGrade(executeGrade),
																					  _target(target)
{
	_isSigned = false;

	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();

	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &f) : _name(f._name),
							   _signGrade(f._signGrade),
							   _executeGrade(f._executeGrade),
							   _target(f._target)
{
	*this = f;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &f)
{
	_isSigned = f._isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

std::string AForm::getTarget() const
{
	return _target;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (_isSigned)
		return;

	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();

	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedExecption();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << (f.isSigned() ? "signed '" : "unsigned '") << f.getName() << "' form\n";
	o << "\ttarget: " << f.getTarget() << "\n";
	o << "\trequired grade to sign: " << f.getSignGrade() << "\n";
	o << "\trequired grade to execute: " << f.getExecuteGrade();
	return o;
}