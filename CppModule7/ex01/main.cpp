#include "iter.hpp"

int main()
{
    const char arr[] = {'H', 'e', 'l', 'l', 'o', ' ', '1', '3', '\n'};
    iter(arr, 9, print<char>);    
}
