#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			std::putchar(std::toupper(argv[i][j]));
		}
	}
	std::cout << "\n";
	return (0);
}