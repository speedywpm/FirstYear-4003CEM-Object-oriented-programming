#include "lab_tax.h"
#include "test_tax.cpp"
#include <iostream>

int main()
{
    int salary = 36000;
    int expected = 4900;
    int tax = income_tax( salary );

    std::cout << "Expected " << expected << " and got " << tax << std::endl;

    return expected != tax;
}
