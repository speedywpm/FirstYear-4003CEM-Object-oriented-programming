#ifndef LAB_ANIMAL_H // header guard
#define LAB_ANIMAL_H

#include <iostream>
#include <string>

/** Class of virtual animals.
 * All animals have name, species, colour and id.
 * Counter is class attribute counting number of Animals **/
class Animal
{
public:
    // Class attribute to producing unique ids for each animal.
    static int counter;
    
    int id;
    std::string name, species, colour;

    Animal( std::string _name, std::string _species, std::string _colour )
    {
        id = counter;
        counter += 1;

        name = _name;
        species = _species;
        colour = _colour;
    }

    void wander()
    {
        std::cout << name << " is wandering" << std::endl;
    }

    void display()
    {
        std::cout << "A " << colour << " " << species << " called " << name << std::endl;
    }
};

int Animal::counter = 0; // remember to initialise the static attributes

/** Class of Animals where species is Dog.  All have Boolean variable friendly. **/
class Dog: public Animal
{    
public:
    bool friendly;

    Dog( std::string _name, std::string _colour, bool _friendly ) 
        : Animal( _name, "Dog", _colour )   // make sure we call the base constructor
    {
        friendly = _friendly;
        
    }
   
    void bark()
    {
        if( friendly )
            std::cout << "Yap!" << std::endl;
        else
            std::cout << "Grrrrr" << std::endl;
    }
    
};

#endif
