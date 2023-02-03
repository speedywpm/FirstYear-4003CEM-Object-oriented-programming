#include <iostream>
#include "ai2.h"

int main()
{
    AI firstAI;
    firstAI.level = 3;
    AI secondAI;

    std::cout << secondAI.numAIs << " " << AI::numAIs << std::endl;

    return 0;
    AI::numAIs = 42;
}
