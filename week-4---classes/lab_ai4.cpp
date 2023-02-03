#include <iostream>
#include "ai4.h"

int main()
{
    AI firstAI;
    AI secondAI;
    
    std::cout << std::endl;
    
    firstAI.say_hello();
    firstAI.increase_level(2);
    secondAI.increase_level(5);
    secondAI.increase_level(7);
    firstAI.say_hello();
    
    return 0;
}
