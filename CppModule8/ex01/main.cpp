#include "Span.hpp"

int main()
{
    Span sp = Span(10);  
    int arr[] = {13, 14, 15, 167};

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addRange(arr, arr + 4);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Unknown exception" << '\n';
    }
    


    return 0;
}