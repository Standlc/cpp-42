#pragma once

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	std::string type;
	public:
		Weapon(std::string type);
		void setType(std::string type);
		const std::string& getType();
};

#endif