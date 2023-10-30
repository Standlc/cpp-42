#include "Zombie.hpp"

int main()
{
	Zombie *newNewZombie = zombieHorde(10, "george");
	for (int i = 0; i < 10; i++)
		newNewZombie[i].announce();
	delete[] newNewZombie;
}