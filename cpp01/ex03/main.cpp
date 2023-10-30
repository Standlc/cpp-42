#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// In HumanB, we have to use a pointer because the Weapon attribute is initialized 
// after the constructer call. Since references require to be initialized at declaration
// we must use pointers.
// In HumanA, we use reference because it forces us to initialize the weapon.
// That way we don't have to worry about null pointers.

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanB jim("Jim");
	// 	jim.setWeapon(club);
	// 	jim.attack();
	// 	club.setType("some other type of club");
	// 	jim.attack();
	// }
	return 0;
}