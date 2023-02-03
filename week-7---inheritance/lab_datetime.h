#ifndef DATETIME_H
#define DATETIME_H

#include "lab_date.h"
#include "lab_time.h"

class DateTime: public Date, public Time
{
public:    
    DateTime( int _day, int _month, int _year, 
              int _hour, int _min ) :
        Date( _day, _month, _year ),    // call the parent constructors
        Time( _hour, _min )
    {}

    void display()
    {
        /* We can still call the methods from the parent even if they
            have been overridden. We just have to explicitally state
            that we want the display() method from Date or Time */
        Time::display();
        std::cout << "on" << std::endl;
        Date::display(); 
    }
};

#endif