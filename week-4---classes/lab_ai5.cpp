#include <iostream>
#include "ai5.h"

int main()
{
    AI firstAI;
    AI secondAI;
    
    std::cout << std::endl;
    
    for( int i=0; i<8; ++i )
    {
        std::cout << "Fight " << i+1 << std::endl;
        secondAI.battle( firstAI );
    }

    std::cout << std::endl;

    firstAI.say_hello();
    secondAI.say_hello();
    
    return 0;
}
