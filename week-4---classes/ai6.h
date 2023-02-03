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

    void battle( AI &other )
    {
        int num1 = RandomValues().damage( level );
        int num2 = RandomValues().damage( other.level );

        if( num1 > num2 )
        {
            std::cout << name << " is the winner!" << std::endl;
            increase_level( 1 );
        }
        else if( num1 < num2 )
        {
            std::cout << other.name << " is the winner!" << std::endl;
            other.increase_level( 1 );
        }
        else
            std::cout << "It's a draw!" << std::endl;
    }
    
    static void how_many_ais()
    {
      std::cout << "There are currently " << numAIs << " AIs" << std::endl;
    }
};   

int AI::numAIs = 0;
