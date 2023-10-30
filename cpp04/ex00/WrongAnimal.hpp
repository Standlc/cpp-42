#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal(std::string type = "");
	WrongAnimal(WrongAnimal const &animal);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const &animal);

	void makeSound() const;
	std::string getType() const;
};

#endif