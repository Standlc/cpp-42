#pragma once

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	void (Harl::*functions[4])();
	std::string levels[4];

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

#endif