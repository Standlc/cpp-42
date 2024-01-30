#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::string _inputFileContent;
    std::map<std::string, float> _exchangeRatesPerYear;
    std::map<std::string, float> _year;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    class FileCannotOpenException : public std::exception
    {
        const char *what() const throw()
        {
            return "Input file could not be opened";
        }
    };

    void parseInputFile(std::string fileName)
    {
        std::ifstream file(fileName);
        if (!file)
        {
            throw FileCannotOpenException();
        }

        try
        {
            getline(file, _inputFileContent, '\0');
        }
        catch (const std::exception &e)
        {
            throw;
        }
        // std::cout << data
    }
};

#endif