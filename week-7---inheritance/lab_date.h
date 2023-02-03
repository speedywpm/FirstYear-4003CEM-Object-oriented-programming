#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <array>

/** Class to store dates **/
class Date
{
private:
    static std::array<int,13> monthDays;

protected:
    int day, month, year;

public:
    Date( int _day=1, int _month=1, int _year=1970 )
    {
        day = _day;
        month = _month;
        year = _year;
    }

    /** method to move to the next date **/
    void forward()
    {
        int numDays = monthDays[month];
        if( day == numDays ) // last day of month
        {
            day = 1;
            if( month == 12 ) // last month of the year
            {
                month = 1;
                year += 1;
            }
            else
                month += 1;
        }
        else
            day += 1;
    }

    void display()
    {
        std::cout << day << "-" << month << "-" << year << std::endl;
    }
};

std::array<int,13> Date::monthDays { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

#endif