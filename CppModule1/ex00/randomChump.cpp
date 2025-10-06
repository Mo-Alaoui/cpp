#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie obj;

    obj.setName(name);
    obj.announce();
}