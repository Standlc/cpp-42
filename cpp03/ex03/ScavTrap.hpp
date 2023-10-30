#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {
	public:
		void guardGate();
		ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();

		void attack(const std::string &target);
};

#endif