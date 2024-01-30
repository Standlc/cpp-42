#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap name constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	this->name = name;
}

ScavTrap::ScavTrap(ScavTrap &scavTrap)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(ScavTrap &s)
{
	ClapTrap::operator=(s);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::guardGate()
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << "ScavTrap is now in gate keeper mode\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (!energyPoints || hitPoints <= 0)
	{
		std::cout << name << " is dead\n";
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!\n";
	energyPoints -= 1;
}
