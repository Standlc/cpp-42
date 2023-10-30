#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "cat constructor called\n";
	_brain = new Brain();
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "cat copy constructor called\n";
	_brain = new Brain(*cat._brain);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "cat destructor called\n";
}

Cat &Cat::operator=(Cat const &cat)
{
	Animal::operator=(cat);
	_brain = cat._brain;
	return *this;
}

//

void Cat::makeSound() const
{
	std::cout << "meow meow\n";
}

std::string &Cat::getBrainIdea(int index)
{
	return _brain->getIdea(index);
}