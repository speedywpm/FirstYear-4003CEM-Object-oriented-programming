#include <iostream>
#include "lab_animal1.h"

int main()
{
    Animal a1( "Clifford", "Dog", "Red" );
    a1.display();
    
    Animal a2( "Tweety", "Bird", "Yellow" );
    a2.display();
    a1.wander();
    return 0;
  
}

