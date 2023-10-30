#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) : AForm(f)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	AForm::operator=(f);
	return *this;
}

void drawThrees(std::ofstream &file)
{
	file << "  ^     ^     ^  " << std::endl;
	file << " ^^^   ^^^   ^^^ " << std::endl;
	file << "^^^^^ ^^^^^ ^^^^^" << std::endl;
	file << "  |     |     |  " << std::endl;
}

void ShrubberyCreationForm::execute_concrete(const Bureaucrat &b) const
{
	AForm::execute(b);

	std::ofstream file(_target + "_shrubbery");
	if (!file)
		throw std::ofstream::failure("error while creating file");

	drawThrees(file);
	file.close();
}
