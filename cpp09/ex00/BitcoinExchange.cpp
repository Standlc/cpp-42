#include "BitcoinExchange.hpp"

// UTILS

bool onlyHas(std::string &str, const std::string &has)
{
    return str.find_first_not_of(has) == std::string::npos;
}

int countCharacter(std::string &str, char c)
{
    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        count += str[i] == c;
    }
    return count;
}

// CONSTRUCTORS

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
    {
        return *this;
    }
    _exchangeRatesPerYear = other._exchangeRatesPerYear;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// METHODS

std::ifstream openFileOrThrow(std::string &filename)
{
    std::ifstream file(&filename[0]);
    if (!file)
    {
        throw std::invalid_argument("Could not open file: " + filename);
    }
    return file;
}

void BitcoinExchange::verifyDateComponentOrThrow(std::string &dateComponent, std::string &maxValue)
{
    int expectedComponentLength = maxValue.length();
    int maxValueToNumber = std::atoi(&maxValue[0]);
    if (dateComponent.length() != expectedComponentLength)
    {
        throw std::invalid_argument("format must be YYYY-MM-DD");
    }
    if (!onlyHas(dateComponent, "0123456789"))
    {
        throw std::invalid_argument("unexpected character");
    }
    double toNumber = std::strtod(&dateComponent[0], NULL);
    if (toNumber < 1 || toNumber > maxValueToNumber)
    {
        throw std::invalid_argument("wrong range");
    }
}

float BitcoinExchange::toFloatOrThrow(std::string &strFloat, float max)
{
    if (strFloat.length() == 0)
    {
        throw std::invalid_argument("exchange rate: not provided");
    }
    if (!onlyHas(strFloat, "0123456789.") || strFloat == ".")
    {
        throw std::invalid_argument("exchange rate: unexpected characters");
    }
    if (countCharacter(strFloat, '.') > 1)
    {
        throw std::invalid_argument("exchange rate: multiple '.'");
    }
    float result = std::strtof(&strFloat[0], NULL);
    if (max != -1 && result > max)
    {
        throw std::invalid_argument("exchange rate: must be in range [0-1000]");
    }
    return result;
}

void BitcoinExchange::verifyDateOrThrow(std::string &date)
{
    std::string dateRanges[3] = {"9999", "12", "31"};
    int componentIndex = 0;
    size_t startPos = 0;
    size_t dateSeparaterPos = 0;

    while (dateSeparaterPos != std::string::npos)
    {
        dateSeparaterPos = date.find_first_of('-', startPos);
        std::string dateComponent = date.substr(startPos, dateSeparaterPos - startPos);
        if (componentIndex > 2)
        {
            throw std::invalid_argument("invalid date: format must be YYYY-MM-DD");
        }

        try
        {
            verifyDateComponentOrThrow(dateComponent, dateRanges[componentIndex]);
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument("invalid date: " + std::string(e.what()));
        }
        componentIndex++;
        startPos = dateSeparaterPos + 1;
    }
}

ExchangeToRetrieve BitcoinExchange::parseInputFileLineOrThrow(std::string &line)
{
    std::string separater = " | ";
    size_t separaterPos = line.find(separater);
    if (separaterPos == std::string::npos)
    {
        throw std::invalid_argument("invalid or no serparater");
    }

    std::string date = line.substr(0, separaterPos);
    this->verifyDateOrThrow(date);

    std::string rawExchangeRate = line.substr(separaterPos + separater.size(), -1);
    float exchangeRateToNumber = this->toFloatOrThrow(rawExchangeRate, 1000);
    return {date, exchangeRateToNumber};
}

void BitcoinExchange::printRetrievedValue(std::string &line)
{
    try
    {
        ExchangeToRetrieve exchange = this->parseInputFileLineOrThrow(line);
        std::map<std::string, float>::iterator it = _exchangeRatesPerYear.lower_bound(exchange.date);
        if (it->first != exchange.date && it != _exchangeRatesPerYear.begin())
        {
            it--;
            float totalValue = it->second * exchange.amount;
            std::cout << exchange.date << " => " << exchange.amount << " = " << totalValue << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[0;31mError: " << e.what() << "\e[1;0m\n";
        return;
    }
}

void BitcoinExchange::printValuesPerYear(std::string filename)
{
    std::ifstream file = openFileOrThrow(filename);
    std::string line;

    getline(file, line);
    if (line != "date | value")
    {
        throw std::invalid_argument("invalid fields line");
    }

    while (getline(file, line))
    {
        if (line.length() == 0)
        {
            continue;
        }
        this->printRetrievedValue(line);
    }
}

void BitcoinExchange::parseDatabase(std::string filename)
{
    std::ifstream file = openFileOrThrow(filename);
    std::string line;

    getline(file, line);
    if (line != "date,exchange_rate")
    {
        throw std::invalid_argument("invalid fields line");
    }

    while (getline(file, line))
    {
        if (line.length() == 0)
        {
            continue;
        }
        size_t separaterPos = line.find_first_of(',');
        if (separaterPos == std::string::npos)
        {
            throw std::invalid_argument("invalid or no serparater");
        }

        std::string date = line.substr(0, separaterPos);
        this->verifyDateOrThrow(date);

        std::string rawExchangeRate = line.substr(separaterPos + 1);
        float exchangeRateToNumber = this->toFloatOrThrow(rawExchangeRate);

        _exchangeRatesPerYear[date] = exchangeRateToNumber;
        // std::cout << date << " " << exchangeRateToNumber << "\n";
    }
}
