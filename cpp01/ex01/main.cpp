#include "Zombie.hpp"

int main()
{
	Zombie *georgeHord = zombieHorde(10, "george");
	for (int i = 0; i < 10; i++)
		georgeHord[i].announce();
	delete[] georgeHord;
	std::cout << "\n";
	Zombie *gregoryHord = zombieHorde(5, "gregory");
	for (int i = 0; i < 5; i++)
		gregoryHord[i].announce();
	delete[] gregoryHord;
}