#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

class Zombie
{
private:

    std::string name;
    
public:

    void setName(std::string newName)
    {
        name = newName;
    }
    
    void announce(void);

};

Zombie* zombieHorde(int N, std::string name);

#endif