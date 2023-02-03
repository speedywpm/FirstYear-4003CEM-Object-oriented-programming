#include <iostream>
using namespace std;

class MyClass
{
private:
	int somePrivateVariable;

	int some_private_method() 
	{
		return somePrivateVariable;
	}

public:
	int somePublicVariable;

	int some_public_method()
	{
		return somePrivateVariable;
	}

	MyClass()
	{
		/* constructor is a member of MyClass
			so has access to private attributes */
		somePublicVariable = 42;
		somePrivateVariable = 69;

		// and methods
		some_private_method();
	}
};

int main()
{
	// creating an instance of the class
	MyClass anInstance;

	// can access public attributes/methods
	anInstance.somePublicVariable = 99;
	anInstance.some_public_method();

	// no access to private outside of class
	// WONT COMPILE
	anInstance.somePrivateVariable = 99; 
	// WONT COMPILE
	anInstance.some_private_method();

	return 0;
}