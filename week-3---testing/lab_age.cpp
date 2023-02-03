#include <iostream>
#include "input.h"
#include "lab_age.h"

int main()
{
    int age;

    // get the user input and deal with invalid values
    try
    {
        std::cout << "Enter an age: ";
        age = input<int>();
    }
    catch( std::runtime_error &e ) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "You are a " << age_description(age) << std::endl;

    return 0;
}
