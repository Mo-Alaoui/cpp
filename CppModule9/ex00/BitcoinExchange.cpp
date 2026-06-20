#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */
BitcoinExchange::BitcoinExchange()
{
    loadExchangeRates();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _exchangeRates = other._exchangeRates;
}
    
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

/* Helpers */
void BitcoinExchange::trim(std::string& str) 
{
    std::string::size_type end = str.find_last_not_of(" \t\n\r\f\v");
    
    if (end != std::string::npos) 
        str.erase(end + 1);
    else 
    {
        str.clear();
        return;
    }

    std::string::size_type start = str.find_first_not_of(" \t\n\r\f\v");
    if (start != std::string::npos) 
    {
        str.erase(0, start);
    }
}

bool    BitcoinExchange::isValidDate(const std::string& date) const
{

    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(date[i]))
            return false;
    }

    int year    = std::atoi(date.substr(0, 4).c_str());
    int month   = std::atoi(date.substr(5, 2).c_str());
    int day     = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2022)
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leapYear)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& rawValue, double& outValue) const
{
    std::stringstream valueParser(rawValue);
    if (!(valueParser >> outValue))
    {
        std::cerr << "Error : not a valid number => " << rawValue << std::endl;
        return false;
    }

    if (outValue < 0)
    {
        std::cerr << "Error : not a positive number.\n";
        return false;
    }

    if (outValue > 1000)
    {
        std::cerr << "Error : too large a number.\n";
        return false;
    }

    return true;
}

double    BitcoinExchange::lookupRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.end())
    {
        --it;
    }
    else if (it->first != date)
    {
        if (it == _exchangeRates.begin())
            throw std::runtime_error("Error: date it before the database range.");
        --it;
    }

    return it->second;
}

void BitcoinExchange::loadExchangeRates()
{
    std::ifstream databaseFile(DATABASE_FILE.c_str());
    
    if (!databaseFile.is_open())
        throw std::runtime_error("Failed to open database file.");
    
    std::string line;
    while (std::getline(databaseFile, line))
    {
        if (line == "date,exchange_rate" || line.empty())
            continue;
        
        std::stringstream ss(line);
        std::string rawRate;
        std::string date;
    
        if (!std::getline(ss, date, ',') || !std::getline(ss, rawRate, ','))
            continue;

        std::stringstream rateParser(rawRate);
        double value;
        if (!(rateParser >> value))
            continue;

        _exchangeRates.insert(std::make_pair(date, value));
    }
}

/* Public Methods */ 
void BitcoinExchange::processInputFile(const std::string& input)
{
    std::ifstream inputFile(input.c_str());
    
    if (!inputFile.is_open())
        throw std::runtime_error("Failed to open input file.");
    
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line == "date | value" || line.empty())
            continue;
        
        std::stringstream ss(line);
        std::string rawValue;
        std::string date;
        double value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, rawValue, '|'))
        {
            std::cerr << "Error : bad input => " << line << std::endl;
            continue;
        }

        trim(date);
        trim(rawValue);

        if (!isValidDate(date))
        {
            std::cerr << "Error : bad input => " << line << std::endl;
            continue;
        }
        
        if (!isValidValue(rawValue, value))
            continue;

        try
        {
            double exchangeRate = lookupRate(date);
            std::cout << date << " => " << value << " = " << value * exchangeRate << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    
    }        
}
