#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap &fragTrap);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap &operator=(FragTrap &frag);

		void highFivesGuys();
};

#endif