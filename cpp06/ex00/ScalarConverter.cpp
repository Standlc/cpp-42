#include "ScalarConverter.hpp"

char _c;
int _i;
float _f;
double _d;
bool _isScientificNotation = false;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &s) { (void)s; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s)
{
	(void)s;
	return *this;
}

int checkScientificNotations(std::string str)
{
	_isScientificNotation = true;

	if (str == "nanf" || str == "-inff" || str == "+inff")
		return FLOAT;

	if (str == "nan" || str == "-inf" || str == "+inf")
		return DOUBLE;

	_isScientificNotation = false;
	return 0;
}

int getType(std::string str)
{
	int i = str[0] == '-' || str[0] == '+';

	if (str.length() == 0)
		throw std::invalid_argument("Argument is empty");

	if (str.length() == 1 && str.find_first_of("1234567890") == std::string::npos)
		return CHAR;

	if (int isScientific = checkScientificNotations(str))
		return isScientific;

	i = str.find_first_not_of("1234567890", i);

	if (str[i] == '.')
	{
		i = str.find_first_not_of("1234567890", i + 1);
		if (str[i] == 'f') {
			if (str[i + 1] != '\0') {
				throw std::invalid_argument("Synthax error in: '" + str + "'");
			}
			return FLOAT;
		}
		if (str[i] == '\0')
			return DOUBLE;
	}

	if (str[i] == '\0')
		return INT;
	throw std::invalid_argument("Synthax error in: '" + str + "'");
}

void showFloatingNumber(std::string type, double number, std::string end)
{
	std::cout << type << ": ";

	std::ostringstream outputStream;
	outputStream << number;

	std::string outputString = outputStream.str();
	std::cout << outputString;

	if (outputString.find(".") == std::string::npos && !_isScientificNotation)
	{
		std::cout << ".0";
	}
	std::cout << end << "\n";
}

void showWholeNumber(std::string type, int number, long min, long max)
{
	std::cout << type << ": ";

	if (_isScientificNotation)
	{
		std::cout << "impossible\n";
	}
	else if (_d < min || _d > max)
	{
		std::cout << "overflow\n";
	}
	else if (type == "char")
	{
		if (!std::isprint(_c))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << _c << "'\n";
	}
	else
		std::cout << number << "\n";
}

void showConversions()
{
	showWholeNumber("char", _c, CHAR_MIN, CHAR_MAX);
	showWholeNumber("int", _i, INT_MIN, INT_MAX);
	showFloatingNumber("float", _f, "f");
	showFloatingNumber("double", _d, "");
}

void ScalarConverter::convert(std::string str)
{
	int _type = getType(str);

	switch (_type)
	{
	case CHAR:
		_c = str[0];
		_i = static_cast<int>(_c);
		_f = static_cast<float>(_c);
		_d = static_cast<double>(_c);
		break;
	case INT:
		_i = std::atoi(&str[0]);
		_c = static_cast<char>(_i);
		_f = static_cast<float>(_i);
		_d = static_cast<double>(_i);
		break;
	case FLOAT:
		_f = std::strtof(&str[0], NULL);
		_c = static_cast<char>(_f);
		_i = static_cast<int>(_f);
		_d = static_cast<double>(_f);
		break;
	default:
		_d = std::strtod(&str[0], NULL);
		_c = static_cast<char>(_d);
		_i = static_cast<int>(_d);
		_f = static_cast<float>(_d);
	}

	if (_type == INT) {
		double intAsDouble = std::strtod(&str[0], NULL);
		if (intAsDouble > INT_MAX || intAsDouble < INT_MIN) {
			throw std::invalid_argument("Integer overflows. Cannot convert input.");
		}
	}
	showConversions();
}

// #include <map>

// int main(int argc, char **argv)
// {
// 	std::map<std::string, int> tests;
// 	std::map<std::string, int> errorTests;
// 	tests["0"] = INT;
// 	tests["-"] = CHAR;
// 	tests["+"] = CHAR;
// 	tests["/"] = CHAR;
// 	tests["."] = CHAR;
// 	tests["f"] = CHAR;
// 	tests["-1"] = INT;
// 	tests["+1"] = INT;
// 	tests["-1.0f"] = FLOAT;
// 	tests["+1.0f"] = FLOAT;
// 	tests["-1.0"] = DOUBLE;
// 	tests["+1.0"] = DOUBLE;
// 	tests["0."] = DOUBLE;
// 	tests[".0"] = DOUBLE;
// 	tests["0.f"] = FLOAT;
// 	tests[".0f"] = FLOAT;
// 	tests["a"] = CHAR;
// 	tests["123"] = INT;
// 	tests["123.123"] = DOUBLE;
// 	tests["123.0"] = DOUBLE;
// 	tests["0.123"] = DOUBLE;
// 	tests["0.0"] = DOUBLE;
// 	tests["+123"] = INT;
// 	tests["-123"] = INT;
// 	tests["+inf"] = DOUBLE;
// 	tests["-inf"] = DOUBLE;
// 	tests["nan"] = DOUBLE;
// 	tests["nanf"] = FLOAT;
// 	tests["2345"] = INT;
// 	tests["-2345"] = INT;
// 	tests["23458765433.0"] = DOUBLE;
// 	tests["?"] = CHAR;

// 	errorTests["--inf"] = 0;
// 	errorTests["--"] = 0;
// 	errorTests["++"] = 0;
// 	errorTests[".."] = 0;
// 	errorTests["0-"] = 0;
// 	errorTests["0+"] = 0;
// 	errorTests["0f"] = 0;
// 	errorTests["-+123"] = 0;
// 	errorTests["123+123"] = 0;
// 	errorTests["12_1"] = 0;
// 	errorTests["3erfv"] = 0;
// 	errorTests["223fe"] = 0;
// 	errorTests["fd2"] = 0;
// 	errorTests["//"] = 0;
// 	errorTests[""] = 0;
// 	errorTests["2345876543"] = INT;
// 	errorTests["??"] = 0;
// 	errorTests[".0."] = 0;
// 	errorTests["0.."] = 0;
// 	errorTests["..0"] = 0;
// 	errorTests["123f"] = 0;

// 	for (std::map<std::string, int>::iterator i = tests.begin(); i != tests.end(); i++)
// 	{
// 		try
// 		{
// 			// int foudtype = ScalarConverter::getType(i->first);
// 			// if (i->second != foudtype)
// 			// {
// 			// 	std::cerr << "\033[1;31m" << "WRONG TYPE: GOT: " << foudtype << " EXPECTED: " << i->second << "\n";
// 			// }
// 			// else
// 			// {
// 			std::cout << "\033[1;32m";
// 			std::cout << i->first << std::endl;
// 			ScalarConverter::convert(i->first);
// 			// ScalarConverter::showConversions();
// 			// }
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << "\033[1;31m" << i->first << ": " << e.what() << '\n';
// 		}
// 		std::cout << std::endl;
// 	}

// 	for (std::map<std::string, int>::iterator i = errorTests.begin(); i != errorTests.end(); i++)
// 	{
// 		try
// 		{
// 			// std::cout << "\033[1;31m" << i->first << std::endl;
// 			ScalarConverter::convert(i->first);
// 			// ScalarConverter::showConversions();
// 			std::cout << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << "\033[1;32m" << i->first << ": " << e.what() << '\n';
// 		}
// 	}

// 	// float f = std::stof(".0");
// 	// std::cout << f << "\n";
// 	// f = std::stof("0.");
// 	// std::cout << f << "\n";
// 	// f = std::stof(".");
// 	// std::cout << f << "\n";
// }
