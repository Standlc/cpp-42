#include "Harl.hpp"

Harl::Harl()
{
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
	void (Harl::*harlFunctions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*harlFunctions[i])();
			break;
		}
	}
}
