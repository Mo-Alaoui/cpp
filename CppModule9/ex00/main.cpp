#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error : expected exactly one argument (input file path)." << std::endl;
        return (1);
    }

    try
    {
        BitcoinExchange btc;
        btc.processInputFile(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    
    return (0);
}
