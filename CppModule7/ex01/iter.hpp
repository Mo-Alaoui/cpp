#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    print(T e)
{
    std::cout << e ;
}

template <typename T, typename F>
void    iter(T* array, const int length,const F& func)
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif
