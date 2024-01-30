#include "FragTrap.hpp"

int main()
{
	FragTrap patrick("Patrick");
	FragTrap alan("Alan");

	std::cout << "\n";

	alan.highFivesGuys();
	patrick.attack("Alan");
	alan.takeDamage(5);
	alan.beRepaired(5);
	patrick.attack("Alan");
	alan.takeDamage(100);
	alan.highFivesGuys();

	std::cout << "\n";

	return 0;
}