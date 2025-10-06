#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *pntObj = new Zombie[N];
    if (!pntObj)
        cout << "Memory allocation failed" << endl;

    int i = 0;
    
    while (i < N)
    {
        std::string tmp;
        std::string ZombieNum;
        std::stringstream ss;

        ss << i;
        ZombieNum = ss.str();
        tmp = name + ZombieNum;

        pntObj[i].setName(tmp);
        i++;
    }

    return (pntObj);
}