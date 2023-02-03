#ifndef VEHICLES_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
public:
    const int wheels;
    const bool motor;

    Vehicle( int _wheels, bool _motor ) : wheels(_wheels), motor(_motor)
    {}

    void move() { std::cout << "Vehicle moving" << std::endl; }
};

class Car: public Vehicle
{
public:
    const int doors;

    Car( int _doors ) : doors(_doors), Vehicle( 4, true )
    {}

    void open_door( int d )
    {
        if( d>0 && d<doors+1 )
            std::cout << "Opening door" << std::endl;
    }

    void rev() { std::cout << "Vrooom!" << std::endl; }
};

class SmallCar: public Car
{
public:
    SmallCar() : Car( 2 ) {}
};

class LargeCar: public Car
{
public:
    LargeCar() : Car( 4 ) {}
};

class Bike: public Vehicle
{
public:
    Bike( bool _motor ) : Vehicle( 2, _motor ) {}

    void do_wheelie() { std::cout << "Doing Wheelie!" << std::endl; }
};

class Bicycle: public Bike
{
public:
    Bicycle() : Bike( false ) {}
};

class MotorBike: public Bike
{
public:
    MotorBike() : Bike( true ) {}

    void rev() { std::cout << "Vrooom!" << std::endl; }
};

#endif

