#include "Harl.hpp"

int getLevel(std::string level, std::string *levels)
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

void complain(Harl myHarl, int levelIndex, std::string *levels)
{
	std::cout << "[" << levels[levelIndex] << "]\n";
	myHarl.complain(levels[levelIndex]);
	std::cout << "\n";
}

void filterHarl(std::string level, std::string *levels)
{
	Harl myHarl;

	switch (getLevel(level, levels))
	{
		case 0:
			complain(myHarl, 0, levels);
		case 1:
			complain(myHarl, 1, levels);
		case 2:
			complain(myHarl, 2, levels);
		case 3:
			complain(myHarl, 3, levels);
			break;
		default:
			std::cout << "Probably complaining about insignificant problem" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Enter a single argument\n";
		return (1);
	}
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	filterHarl(argv[1], levels);
	return (0);
}