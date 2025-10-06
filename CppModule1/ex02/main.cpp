#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

int main()
{
    std::string string     = "HI HTIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
 
    cout << "Print the memory address" << endl;
    cout << std::left << std::setw(40);
    cout << "The memory address of the string: " << "[" << &string << "]\n";

    cout << std::left << std::setw(40);
    cout << "The memory address held by stringPTR: " << "[" << stringPTR<< "]\n";
    
    cout << std::left << std::setw(40);
    cout << "The memory address held by stringREF: " << "[" << &stringREF << "]\n\n";
    
    cout << "Print the value\n";
    cout << std::left << std::setw(40);
    cout << "The value of the string variable: " << "[" << string << "]\n";

    cout << std::left << std::setw(40);
    cout << "The value pointed to by stringPTR: " << "[" << *stringPTR << "]\n";
    
    cout << std::left << std::setw(40);
    cout << "The value pointed to by stringREF: " << "[" << stringREF << "]";
    cout << endl;

    
    return (0);
}
