#ifndef TIME_H
#define TIME_H

#include <iostream>

/** Class for 24 hour time **/
class Time
{
protected:
    int hour, min;

public:
    Time( int _hour=0, int _min=0 )
    {
        hour = _hour;
        min = _min;
    }
    
    /** move time on by 1 minute **/
    void tick()
    {
        if( min == 59 ) 
        {
            min = 0;
            if( hour == 23 )
                hour = 0;
            else
                hour += 1;
        }
        else
            min += 1;
    }

    void display()
    {
        std::cout << hour << ":" << min << std::endl;
    }
};

#endif