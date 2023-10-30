#include "Zombie.hpp"

void randomChump( std::string name );
Zombie *newZombie( std::string name );

int main()
{
	randomChump("zomzom");
	randomChump("dumdum");
	Zombie *newNewZombie = newZombie("zombie zom");
	delete newNewZombie;
}