#include "FragTrap.hpp"

int main()
{
	FragTrap patrick("Patrick");
	FragTrap alan("Alan");

	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(5);
	patrick.attack("Alan");
	alan.takeDamage(100);
	return 0;
}