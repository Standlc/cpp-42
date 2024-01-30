#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &s);

		void attack(const std::string &target);
		void guardGate();
};

#endif