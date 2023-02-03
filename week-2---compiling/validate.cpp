#include "passwords.h"

#include <iostream>

int main()
{
    std::string userInput;

    std::cout << "Enter a password to test if it is a good one" << std::endl;
    std::cout << "  Obviously you shouldn't use a real one: ";

    std::cin >> userInput;

    if( good_password( userInput ) )
        std::cout << "Good password" << std::endl;
    else
        std::cout << "Bad password" << std::endl;    

    return 0;
}