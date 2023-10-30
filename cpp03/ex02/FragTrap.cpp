#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}


FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	this->name = name;
}

FragTrap::FragTrap(FragTrap &FragTrap)
{
	std::cout << "FragTrap Copy constructor called\n";
	*this = FragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

void FragTrap::highFivesGuys()
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << "FragTrap " << name << " is randomly giving high fives\n";
}
