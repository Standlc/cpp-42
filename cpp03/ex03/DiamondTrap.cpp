#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DiamondTrap constructor called\n";
	energyPoints = 50;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI()
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << "I am " << name << ", " << ClapTrap::name << std::endl;
}