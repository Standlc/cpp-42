#include "ScavTrap.hpp"

int main()
{
	ScavTrap patrick("Patrick");
	ScavTrap alan("Alan");

	std::cout << "\n";

	alan.guardGate();
	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(100);
	patrick.attack("Alan");
	alan.takeDamage(105);
	alan.guardGate();

	std::cout << "\n";

	return 0;
}