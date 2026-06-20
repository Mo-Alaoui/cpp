#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

static const std::string DATABASE_FILE = "./cpp_09/data.csv";

class BitcoinExchange
{
private:
    std::map<std::string, double> _exchangeRates;

    bool    isValidValue(const std::string& raw, double& outValue) const;
    bool    isValidDate(const std::string& date) const;
    void    trim(std::string& str);
    void    loadExchangeRates();
    double  lookupRate(const std::string& date) const;

public :
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void    processInputFile(const std::string& input);
};

#endif