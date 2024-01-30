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

FragTrap &FragTrap::operator=(FragTrap &frag)
{
	ClapTrap::operator=(frag);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is randomly giving high fives\n";
}
