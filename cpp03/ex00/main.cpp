#include "ClapTrap.hpp"

int main()
{
	ClapTrap patrick("Patrick");
	ClapTrap alan("Alan");

	std::cout << "\n";

	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(100);
	patrick.attack("Alan");
	alan.takeDamage(105);
	alan.beRepaired(10);

	std::cout << "\n";

	return 0;
}