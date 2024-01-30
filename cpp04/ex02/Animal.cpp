#include "Animal.hpp"

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Animal constructor called\n";
}

Animal::Animal(Animal const &a)
{
	std::cout << "Animal copy constructor called\n";
	*this = a;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal &Animal::operator=(Animal const &a)
{
	_type = a._type;
	return *this;
}

//

std::string Animal::getType() const
{
	return _type;
}