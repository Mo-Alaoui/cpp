#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <string>
#include <iostream>

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

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif