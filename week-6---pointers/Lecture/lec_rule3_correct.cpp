#include <iostream>
using namespace std;

class Thingy
{
private:
	double* pointer;

public:
	/** constructor **/
	Thingy( double value )
	{
		pointer = new double;
		*pointer = value;
	}

	/** copy constructor, rule of 3 - 1/3 **/
	Thingy( const Thingy& other )
	{
		pointer = new double;
		*pointer = *(other.pointer);
	}

	/** copy assignment, rule of 3 - 2/3 **/
	Thingy& operator=( const Thingy& other )
	{
		*pointer = *(other.pointer);
	}

	/** destructor, rule of 3 - 3/3 **/
	~Thingy()
	{
		delete pointer;
	}

	friend size_t get_memory_address( const Thingy& thing );
};

size_t get_memory_address( const Thingy& thing ) { return (size_t)thing.pointer; }

int main()
{
	Thingy thingA( 123.456 );   // calls the constructor
	Thingy thingB = thingA;     // calls the copy constructor
	Thingy thingC( 456.789 );   
	thingC = thingB;            // calls copy assignment

	cout << "If the addresses aren't all unique we have a problem" << endl;
	cout << "thingA: " << get_memory_address( thingA ) << endl;
	cout << "thingB: " << get_memory_address( thingB ) << endl;
	cout << "thingC: " << get_memory_address( thingC ) << endl;
	
	return 0;
}
