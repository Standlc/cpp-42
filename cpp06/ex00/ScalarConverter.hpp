#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <iostream>
#include <climits>
#include <sstream>
#include <string>

#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>
#include <cfloat>
#include <iomanip>

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
	ScalarConverter();
	ScalarConverter(const ScalarConverter &s);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &s);

public:
	static void convert(std::string str);
};

#endif