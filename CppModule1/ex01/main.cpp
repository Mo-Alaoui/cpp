#include "Zombie.hpp"

int main()
{
    Zombie *pntObj;
    unsigned int HordeNum = 10;

    pntObj = zombieHorde(HordeNum, "foo");
    
    for (unsigned int i = 0; i < HordeNum; i++)
    {
        pntObj[i].announce();
    }

    delete[] pntObj;
}
