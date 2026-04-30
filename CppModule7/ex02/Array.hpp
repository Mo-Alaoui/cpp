#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array 
{
private:
    T* _arr;
    unsigned int _size;

public :
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](const unsigned int i);
    unsigned int size() const;
    ~Array();
};

#include "Array.tpp"

#endif