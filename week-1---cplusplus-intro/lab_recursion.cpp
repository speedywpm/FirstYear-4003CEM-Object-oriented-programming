#include <iostream>
#include "lab_recursion.h"

int main()
{
    std::cout << std::boolalpha; // print booleans as "true" and "false"

    std::cout << "\"racecar\" a palindrome? " << is_palindrome( "racecar" ) << std::endl;
    std::cout << "\"wibble\" a palindrome? " << is_palindrome( "wibble" ) << std::endl;

    return 0;
}