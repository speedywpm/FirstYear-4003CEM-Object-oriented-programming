#include <iostream>
using namespace std;

class MyClass
{
public:
	int someVariable;

	MyClass()
	{
		someVariable = 42;
	}
};

class MyClassB
{
public:
	int someVariable;
	const float someConst;

	MyClassB() : someConst(1.23f)
	{
		someVariable = 42;
	}
};

int main()
{
	// creating an instance of the class
	MyClass anInstance;

	// using an attribute from the instance
	anInstance.someVariable = 42;

	return 0;
}