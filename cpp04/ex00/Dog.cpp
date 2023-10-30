#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog constructor called\n";
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(Dog const &dog)
{
	Animal::operator=(dog);
	return *this;
}

//

void Dog::makeSound() const
{
	std::cout << "woof woof\n";
}