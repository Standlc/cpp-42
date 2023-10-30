#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice constructor called\n";
}

Ice::Ice(Ice const &a) : AMateria(a)
{
	// std::cout << "Ice copy constructor called\n";
	*this = a;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called\n";
}

Ice &Ice::operator=(Ice const &a)
{
	AMateria::operator=(a);
	return *this;
}

// METHODS

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice *Ice::clone() const
{
	Ice *clone = new Ice();
	return clone;
}