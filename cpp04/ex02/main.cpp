#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// won't work because Animal class is abstract
	// Animal animal;

	std::string dogWords[5] = {"hey", "yo", "wow", "123", "456"};
	std::string catWords[5] = {"shish", "dude", "mercedes", "cat", "bark"};

	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "\n";
	}

	for (int i = 0; i < 5; i++)
		((Dog *)animals[0])->getBrainIdea(i) = dogWords[i];
	Dog dog_copy = Dog(*((Dog *)animals[0]));
	std::cout << "\n";
	for (int i = 0; i < 5; i++)
		std::cout << dog_copy.getBrainIdea(i) << "\n";
	std::cout << "\n";

	//

	for (int i = 0; i < 5; i++)
		((Dog *)animals[2])->getBrainIdea(i) = catWords[i];
	Cat cat_copy = Cat(*((Cat *)animals[2]));
	std::cout << "\n";
	for (int i = 0; i < 5; i++)
		std::cout << cat_copy.getBrainIdea(i) << "\n";
	std::cout << "\n";

	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << "\n";
	}
	return (0);
}