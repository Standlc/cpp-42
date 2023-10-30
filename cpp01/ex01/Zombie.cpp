#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "destroying: " << name << std::endl;
}

void Zombie::announce()
{
	std::cout << name <<  ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string newName)
{
	name = newName;
}