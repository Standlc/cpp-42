#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor called\n";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called\n";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	this->name = name;
}

ClapTrap::ClapTrap(ClapTrap &clapTrap)
{
	std::cout << "Copy constructor called\n";
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap &clapTrap)
{
	std::cout << "Operator called\n";
	name = clapTrap.name;
	hitPoints = clapTrap.hitPoints;
	energyPoints = clapTrap.energyPoints;
	attackDamage = clapTrap.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
	energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << name << " takes " << amount << " damage points!\n";
	hitPoints -= amount;
	if (hitPoints <= 0)
		std::cout << name << " died\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	energyPoints -= 1;
	hitPoints += amount;
}
