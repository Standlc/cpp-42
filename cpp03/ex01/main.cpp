#include "ScavTrap.hpp"

int main()
{
	ScavTrap patrick("Patrick");
	ScavTrap alan("Alan");

	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(100);
	patrick.attack("Alan");
	alan.takeDamage(105);
	return 0;
}