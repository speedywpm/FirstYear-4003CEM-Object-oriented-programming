#include "lab_leap.h"
#include "input.h"

#include <iostream>

int main()
{
    int year;

    // get the user input and deal with invalid values
    try
    {
        std::cout << "Enter the year you want to check: ";
        year = input<int>();
    }
    catch( std::runtime_error &e ) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // is it a leap year?
    bool leap = is_leap( year );

    // print leap year message
    std::cout << year << " is";
    if( !leap ) std::cout << "n't";
    std::cout << " a leap year" << std::endl;

    return 0;
}
