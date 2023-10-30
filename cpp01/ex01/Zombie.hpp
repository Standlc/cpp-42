#pragma once

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;
	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string newName);
};

Zombie* zombieHorde( int N, std::string name );

#endif