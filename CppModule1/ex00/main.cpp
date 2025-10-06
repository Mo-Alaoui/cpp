#include "Zombie.hpp"

int main()
{
    Zombie *pntObj;
    Zombie *pntObj1;

    // creates zombie and zombie announces itself
    randomChump("random foo");

    // creates zombie and zombie and return it
    pntObj = newZombie("new foo");
    pntObj->announce();
    
    pntObj1 = newZombie("new_foo_number_2");
    pntObj1->announce();

    delete pntObj;
    delete pntObj1;
}
