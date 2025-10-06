#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;

class Megaphone
{
public :
    static void toupper_str(std::string &str)
    {
        for (std::size_t i = 0; i < str.size(); i++)
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }

    static void print(int argc, char *argv[])
    {
        if (argc == 1)
        {
            cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
            return ;    
        }

        for (int i = 1; i < argc; i++)
        {
            std::string word = argv[i];
            toupper_str(word);
            (argc - 1 > i) ? cout << word << " " : cout << word;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    Megaphone::print(argc, argv);
}