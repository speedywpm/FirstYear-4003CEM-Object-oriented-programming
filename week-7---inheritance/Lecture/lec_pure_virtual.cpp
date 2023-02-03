#include <iostream>
#include <string>
using namespace std;

class Pet
{
private: 
	std::string name;
public:
	Pet( std::string _name ) : name(_name) {}

	virtual void speak() const = 0;

	void walk()
	{
		cout << "Wandered round a bit" << endl;
	}
};

class Dog : public Pet
{
public:
	/** make sure we call parent constructor **/
	Dog( std::string _name ) : Pet(_name) {}

	/** overrides parent version of speak() **/
	void speak() const
	{
		cout << "Woof" << endl;
	}
};

class Cat : public Pet
{
public:
	/** make sure we call the parent constructor **/
	Cat( std::string _name ) : Pet(_name) {}

	/** overrides the parent implementation of speak() **/
	void speak() const
	{
		cout << "Meow" << endl;
	}
};

int main()
{
	/* Pet p( "Paul" ); can't create objects of class with pure virtuals */
	Dog d( "Dugg" );
	Cat c( "Charles" );

	d.speak(); // Woof
	c.speak(); // Meow

	d.walk(); // Wandered round a bit
	c.walk(); // Wandered round a bit

	return 0;
}