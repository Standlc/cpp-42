#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog constructor called\n";
	_brain = new Brain;
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called\n";
	_brain = new Brain(*dog._brain);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(Dog const &dog)
{
	Animal::operator=(dog);
	_brain = dog._brain;
	return *this;
}

//

void Dog::makeSound() const
{
	std::cout << "woof woof\n";
}

std::string &Dog::getBrainIdea(int index)
{
	return _brain->getIdea(index);
}