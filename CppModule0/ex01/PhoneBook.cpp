#include "PhoneBook.hpp"
#include <string>

int main()
{
    PhoneBook phoneBook1;
    string user_cmd;
    
    while (true)
    {
        cout << "Enter one of three commands. ADD, SEARCH, EXIT: ";
        getline(cin, user_cmd);

        if (user_cmd == "ADD")
        {
            phoneBook1.addContacts();
        }
        else if (user_cmd == "SEARCH")
        {
            phoneBook1.searchContacts();
        }
        else if (user_cmd == "EXIT")
        {
            break;
        }
    };
    
    return (0);
}