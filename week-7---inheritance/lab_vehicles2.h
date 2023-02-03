#ifndef VEHICLES_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
public:
    const int wheels;

    Vehicle( int _wheels ) : wheels(_wheels)
    {}

    void move() { std::cout << "Vehicle moving" << std::endl; }
};

class Bike: public Vehicle
{
public:
    Bike() : Vehicle( 2 ) {}

    void do_wheelie() { std::cout << "Doing Wheelie!" << std::endl; }
};

class MotorisedVehicle: public Vehicle
{
public:
    MotorisedVehicle( int _wheels ) : Vehicle(_wheels) {}

    void rev() { std::cout << "Vrooom!" << std::endl; }
};

class Bicycle: public Bike
{
public:
    Bicycle() : Bike() {}
};

class MotorBike: public Bike, public MotorisedVehicle
{
public:
    MotorBike() : Bike(), MotorisedVehicle(2) {}
};

class Car: public MotorisedVehicle
{
public:
    const int doors;

    Car( int _doors ) : doors(_doors), MotorisedVehicle( 4 )
    {}

    void open_door( int d )
    {
        if( d>0 && d<doors+1 )
            std::cout << "Opening door" << std::endl;
    }
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





#endif

