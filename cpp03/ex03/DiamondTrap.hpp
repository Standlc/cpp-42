#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	std::string name;

	public:
		void whoAmI();
		DiamondTrap(std::string name);
		~DiamondTrap();
};

#endif