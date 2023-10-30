#pragma once

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
		void setName(std::string newName);
};

#endif