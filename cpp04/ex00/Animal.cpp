#include "Animal.hpp"

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Animal constructor called\n";
}

Animal::Animal(Animal const &a)
{

	std::cout << "Animal copy constructor called\n";
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

void Animal::makeSound() const
{
	std::cout << "animal sound\n";
}

std::string Animal::getType() const
{
	return _type;
}