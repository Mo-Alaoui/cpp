#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

# define MAX_CONTACATS 8

struct ContactData
{
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;
};

class Contact
{
private:
    ContactData contact;

    bool isAllAlphaSpace(string str)
    {
        for (unsigned int i = 0; i < str.length(); i++)
        {
            if (!(std::isalpha(str[i]) || std::isspace(str[i])))
                return (false);
        }
        return (true);
    }

    bool isStrPhoneNumber(string str)
    {
        unsigned int len = str.size();
        unsigned int valid_len;

        if (str[0] == '+')  valid_len = 11;
        else                valid_len = 10;

        if (len < valid_len) return (false);
        for (unsigned int i = 1; i < len; i++)
        {
            if (!(str[0] != '+' || !std::isdigit(str[0])))
                    return (false);
            if (!std::isdigit(str[i]))
                return (false);
        }
        return (true);
    }

public:

    Contact()
    {
        contact.first_name = "void";
        contact.last_name = "void";
        contact.nickname = "void";
        contact.phone_number = "void";
        contact.darkest_secret = "void";
    }

    void setContact()
    {
        while (true) 
        {
            cout << "Enter first name: ";
            getline(cin, contact.first_name);

            if (!cin.eof()
                    && !contact.first_name.empty() 
                    && isAllAlphaSpace(contact.first_name))
                break;
        };

        while (true) 
        {
            cout << "Enter last name: ";
            getline(cin, contact.last_name);

            if (!cin.eof() 
                    && !contact.last_name.empty() 
                    && isAllAlphaSpace(contact.last_name))
                break;
        };

        while (true) 
        {
            cout << "Enter nickname: ";
            getline(cin, contact.nickname);

            if (!cin.eof() 
                    && !contact.nickname.empty() 
                    && isAllAlphaSpace(contact.nickname))
                break;
        };

        while (true) 
        {
            cout << "Enter phone number: ";
            getline(cin, contact.phone_number);

            if (!cin.eof() 
                    && !contact.phone_number.empty() 
                    && isStrPhoneNumber(contact.phone_number))
                break;
        };

        while (true) 
        {
            cout << "Enter darkest secret: ";
            getline(cin, contact.darkest_secret);

            if (!cin.eof() 
                    && !contact.darkest_secret.empty())
                break;
        };
    }

    void printHedere()
    {
        for (int i = 0; i < 44; i++)
            cout << "-";
        cout << endl;
        cout << std::right << std::setw(10) << "index"      << "|";
        cout << std::right << std::setw(10) << "First name" << "|";
        cout << std::right << std::setw(10) << "Last name"  << "|";
        cout << std::right << std::setw(10) << "Nickname";
        cout << endl;
        for (int i = 0; i < 44; i++)
            cout << "-";
        cout << endl;
    }

    void printContactWithFormat(std::string str, bool endline)
    {
        std::string tmp;

        tmp = str;
        if (tmp.length() >= 10)
            tmp.replace(tmp.begin() + 9, tmp.begin() + 10, ".");
        cout << std::right << std::setw(10) << tmp.substr(0, 10);
        if (!endline) cout << "|";
        else          cout << endl;
    }

    void getContact(int index)
    {
        if (contact.first_name.empty())
            return ;
        if (index == 0)
            printHedere();

        cout << std::right << std::setw(10) << index + 1 << "|";
        printContactWithFormat(contact.first_name, false);
        printContactWithFormat(contact.last_name, false);
        printContactWithFormat(contact.nickname, true);
    }

    void getContact()
    {
        if (contact.first_name.empty())
            return ;
        cout << "First name     : " << contact.first_name     << endl;
        cout << "Last name      : " << contact.last_name      << endl;
        cout << "Nickname       : " << contact.nickname       << endl;
        cout << "Phone number   : " << contact.phone_number   << endl;
        cout << "Darkest secret : " << contact.darkest_secret << endl;
    }
};

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACATS];
    static int contact_num;

public:

    void addContacts()
    {
        contacts[contact_num++ % MAX_CONTACATS].setContact();
    }

    void searchContacts()
    {
        int i = 0;

        while (i < MAX_CONTACATS)
        {
            contacts[i % MAX_CONTACATS].getContact(i);
            i++;            
        }

        if (contact_num != 0)
        {
            string user_input = "";
            int    index;

            while (true)
            {
                cout << "Enter index for contact to display full info: ";
                getline(cin, user_input);

                std::size_t find_space = user_input.find(" ");
                if (find_space != std::string::npos)
                    continue;

                std::stringstream ss(user_input);
                if (ss >> index && ss.eof() && index > 0)
                {
                    contacts[index - 1].getContact();
                    break;
                }
            };
        }
    }
};

int PhoneBook::contact_num = 0;
#endif