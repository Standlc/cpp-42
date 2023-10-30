#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(Dog const &dog);
	~Dog();
	Dog &operator=(Dog const &dog);

	void makeSound() const;
	std::string &getBrainIdea(int index);
};

#endif