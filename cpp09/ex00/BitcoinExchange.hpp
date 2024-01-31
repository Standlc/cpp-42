#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cfloat>
#include <iomanip>

typedef struct ExchangeToRetrieve
{
    std::string date;
    float amount;
} ExchangeToRetrieve;

class BitcoinExchange
{
private:
    std::map<std::string, float> _exchangeRatesPerYear;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void verifyDateComponentOrThrow(std::string &dateComponent, std::string &maxValue);
    float toFloatOrThrow(std::string &strFloat, float max = -1);
    void verifyDateOrThrow(std::string &date);
    void parseDatabase(std::string filename);
    ExchangeToRetrieve parseInputFileLineOrThrow(std::string &line);
    void printRetrievedValue(std::string &line);
    void printValuesPerYear(std::string filename);
};

#endif