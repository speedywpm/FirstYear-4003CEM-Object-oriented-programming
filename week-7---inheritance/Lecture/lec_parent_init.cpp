#include <iostream>
#include <type_traits>
using namespace std;

class Animal
{
public:
	const int legs;

	Animal( int _legs ) : legs(_legs) {}
};

class Dog : public Animal
{
public:
	// Notice the call to the parent constructor
	Dog() : Animal( 4 ) {}
};

int main()
{
	Dog dog;

	cout << dog.legs << endl; // 4

	return 0;
}
