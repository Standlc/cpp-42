#include <map>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\e[0;31mError: one input file is required\n";
        return 1;
    }

    BitcoinExchange bitcoinDB;

    try
    {
        bitcoinDB.parseDatabase("data.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[0;31mDB Error: " << e.what() << "\e[1;0m\n";
        return 1;
    }

    try
    {
        bitcoinDB.printValuesPerYear(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[0;31mError: " << e.what() << "\e[1;0m\n";
    }

    return 0;
}