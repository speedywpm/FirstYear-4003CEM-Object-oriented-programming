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

    void say_hello() const
    {
        std::cout << name << ":"
                << " Hello! My name is " << name
                << " I am level " << level << std::endl;
    }

    void increase_level( int num )
    {
        if( level + num >= 10 )
        {
            level = 10;
            std::cout << "Maximum level reached" << std::endl;
        }
        else
            level += num;
    }
};   

int AI::numAIs = 0;
