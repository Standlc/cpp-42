#pragma once

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

class Harl {
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

#endif