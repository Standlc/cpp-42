#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &a) : AMateria(a)
{
	*this = a;
}

Ice::~Ice()
{
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