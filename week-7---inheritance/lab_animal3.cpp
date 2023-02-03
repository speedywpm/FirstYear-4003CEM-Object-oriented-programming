#include <iostream>
#include "lab_animal3.h"

int main()
{
    Dog myDog( "Clifford", "Red", true );
    myDog.bark();
    Bird myBird("Tweety", "Yellow", true);
    myBird.flap();
    myBird.wander();

    return 0;
}
