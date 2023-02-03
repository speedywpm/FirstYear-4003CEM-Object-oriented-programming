#include <iostream>
#include "lab_sqrt.h"

int main()
{
    float answer = my_sqrt(9);
    std::cout << "Square root of 9 is 3." << std::endl;
    std::cout << "my_sqrt() returns " << answer << std::endl;

    return 0;
}