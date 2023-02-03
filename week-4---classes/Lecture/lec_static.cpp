#include <iostream>
using namespace std;

class MyClass
{
public:
	int someVariable;
	static int countClasses;

	MyClass( int value )
	{
		someVariable = value;
		countClasses++;
	}
};

// initialise static variable
int MyClass::countClasses = 0;

int main()
{
	// creating an instance of the class
	MyClass a(42);

	cout << a.someVariable << endl; // 42
	cout << a.countClasses << endl; // 1

	// create another instance
	MyClass b(69);

	cout << b.someVariable << endl; // 69
	cout << b.countClasses << endl; // 2

	// can also access via class name
	cout << MyClass::countClasses << endl; // 2

	return 0;
}