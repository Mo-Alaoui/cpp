#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: expected exactly one argument." << std::endl;
        return (1);
    }

    try
    {
        RPN evaluator;
        std::cout << evaluator.evaluate(argv[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}