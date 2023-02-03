#include <iostream>
using namespace std;

class MyClass
{
private:
	int somePrivateVariable;

public:
	void setter_method( int value )
	{
		// setters let us have value checks
		if( value >= 0 )
			somePrivateVariable = value;
	}

	/* notice the const on the end of the 
		header. means that this method 
		doesn't change class in any way*/
	int getter_method() const
	{
		/* without a getter, attribute 
			would need to be public,
			would mean anyone could
			change the value. */
		return somePrivateVariable;
	}
};

int main()
{
	// creating an instance of the class
	MyClass anInstance;

	anInstance.setter_method( 42 );
	int value = anInstance.getter_method();

	return 0;
}