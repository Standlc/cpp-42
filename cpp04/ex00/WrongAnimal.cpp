#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &animal)
{
	*this = animal;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	_type = animal._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "wrong animal sound\n";
}

std::string WrongAnimal::getType() const
{
	return _type;
}