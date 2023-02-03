#include <iostream>
#include "lab_animal4.h"

int main()
{
    Dog a1( "Clifford", "Red", true );
    a1.display();
    
    Dog a2( "Gnasher", "Grey", false );
    a2.display();
    
    Bird a3("Tweety", "Yellow", true);
    a3.display();
    return 0;
}
