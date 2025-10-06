#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *pntObj = new Zombie;
    if (!pntObj)
        cout << "Memory allocation failed" << endl;

    pntObj->setName(name);
    return (pntObj);
}