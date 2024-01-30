#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor called\n";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
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
	std::cout << "attributes: " << "HP: " << hitPoints << " EP: " << energyPoints << " AD: " <<attackDamage << "\n";
}