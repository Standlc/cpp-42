#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "cat constructor called\n";
}

Cat::~Cat()
{
	std::cout << "cat destructor called\n";
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "cat copy constructor called\n";
}

Cat &Cat::operator=(Cat const &cat)
{
	Animal::operator=(cat);
	return *this;
}

//

void Cat::makeSound() const
{
	std::cout << "meow meow\n";
}