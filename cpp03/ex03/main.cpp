#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap patrick("Patrick");
	DiamondTrap alan("Alan");

	patrick.attack("Alan");
	patrick.highFivesGuys();
	patrick.guardGate();
	alan.takeDamage(5);
	alan.beRepaired(5);
	patrick.attack("Alan");
	alan.takeDamage(100);
	patrick.whoAmI();
	return 0;
}