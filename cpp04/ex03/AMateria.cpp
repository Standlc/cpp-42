#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
	// std::cout << "AMateria constructor called\n";
}

AMateria::AMateria()
{
	// std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(AMateria const &a)
{
	// std::cout << "AMateria copy constructor called\n";
	*this = a;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called\n";
}

AMateria &AMateria::operator=(AMateria const &a)
{
	_type = a._type;
	return *this;
}

// METHODS

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use\n";
}
