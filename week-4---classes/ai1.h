#include <iostream>
#include "randomvalues.h"

/** A class for AI characters in a game. **/
class AI
{
public:
    std::string name;
    int level;
    static int numAIs;
    
    AI()
    {
        name = RandomValues().name();
        level = 1;
        numAIs += 1;

        std::cout << "AI " << name << " created" << std::endl;
    }
};

int AI::numAIs = 0;
