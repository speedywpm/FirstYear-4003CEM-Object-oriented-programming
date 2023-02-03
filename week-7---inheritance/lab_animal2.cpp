#include <iostream>
#include "lab_animal2.h"

int main()
{
    Dog a1( "Clifford", "Red", true );
    a1.bark();
    a1.wander();
    std::cout << a1.counter << std::endl;
    return 0;
}
