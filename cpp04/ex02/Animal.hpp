#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal(std::string type = "");
	Animal(Animal const &a);
	virtual ~Animal();
	Animal &operator=(Animal const &a);

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif