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
};

class Dog : public Animal
{
public:
	Dog( string _name ) : Animal( _name, 4 ) {}
};

class Bird : private Animal
{
public:
	Bird( string _name ) : Animal( _name, 2 ) {}
};

int main()
{
	Dog dog( "Dugg" );
	Bird bird( "Tweety" );

	// Won't compile, private attribute
	cout << dog.legs << endl; 
	
	// public attribute, everything is fine, "Dugg"
	cout << dog.name << endl; 

	// pubic attribute but private inheritance, won't compile
	cout << bird.name << endl; 

	return 0;
}
