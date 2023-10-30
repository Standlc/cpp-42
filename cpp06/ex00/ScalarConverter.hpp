#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <iostream>
#include <limits>
#include <sstream>

enum
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
private:
	static int _type;
	static char _c;
	static int _i;
	static float _f;
	static double _d;

	static bool _isScientificNotation;

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &s);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &s);

	static void convert(std::string str);
	static int getType(std::string str);
	static int checkScientificNotations(std::string str);
	static void showConversions();
	static void showWholeNumber(std::string type, int number, long min, long max);
	static void showFloatingNumber(std::string type, double number, std::string end);
};

#endif