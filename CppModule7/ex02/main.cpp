#include "Array.hpp"

int main()
{

    try 
    {
        Array<int> A(10);

        A[0] = 13;
        A[1] = 14;
        A[9] = 15;
        // A[112] = 3;
        // int r = A[1] * A[9];
        // std::cout << A[1] << " * " << A[9] << " = " << r << std::endl;
        // std::cout << A[0] << A[1] << A[2] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown error";
    }

}
