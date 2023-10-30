#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat")
{
	std::cout << "WrongCat constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(WrongCat const &wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &cat)
{
	WrongAnimal::operator=(cat);
	return *this;
}

//

void WrongCat::makeSound() const
{
	std::cout << "meow meow\n";
}