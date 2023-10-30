#include "Harl.hpp"

Harl::Harl()
{
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Harl::~Harl()
{	
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\n";
}

void Harl::error( void )
{
	std::cout << "This is unacceptable !\n";
}

void Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}
