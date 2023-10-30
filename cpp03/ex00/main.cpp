#include "ClapTrap.hpp"

int main()
{
	ClapTrap patrick("Patrick");
	ClapTrap alan("Alan");

	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(100);
	patrick.attack("Alan");
	alan.takeDamage(105);
	return 0;
}