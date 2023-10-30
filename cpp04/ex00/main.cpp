#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal("Dugong");
	std::cout << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "\n";
	
	const Animal *dog = new Dog();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "\n";

	const Animal *cat = new Cat();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "\n";
	std::cout << "\n";

	const WrongAnimal *wrongAnimal = new WrongAnimal("Narval");
	std::cout << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << "\n";
	
	const WrongAnimal *wrongCat = new WrongCat;
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << "\n";


	delete meta;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;

	// Animal a;
	// Animal b(a);
	return (0);
}