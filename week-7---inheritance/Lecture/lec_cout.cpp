#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
	const int legs;

public:
	string name;

	Animal( string _name, int _legs ) : name(_name), legs(_legs) {}

    friend std::ostream& operator<<( std::ostream&, const Animal& );
};

// this is the function that runs when we try to cout an Animal
std::ostream& operator<<( std::ostream& os, const Animal& animal )
{
    os << animal.name << " has " << animal.legs << " legs";
	return os;
}

class Dog : public Animal
{
public:
	Dog( string _name ) : Animal( _name, 4 ) {}
};

int main()
{
	Dog dog( "Dugg" );

	// can just cout the object
	cout << dog << endl; // "Dugg has 4 legs"

	return 0;
}
