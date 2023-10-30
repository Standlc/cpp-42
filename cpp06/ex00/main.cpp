#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	try
	{
		ScalarConverter::convert(argv[1]);
		ScalarConverter::showConversions();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}