#include <iostream>
#include "lab_animal5.h"

int main()
{
    Animal a( "Clifford", "Dog", "Red" );
    std::cout << a << std::endl;

    Dog d( "Gnasher", "Grey", false );
    std::cout << d << std::endl;

    Bird b( "Tweety", "Yellow", true );
    std::cout << b << std::endl;

    return 0;
}
