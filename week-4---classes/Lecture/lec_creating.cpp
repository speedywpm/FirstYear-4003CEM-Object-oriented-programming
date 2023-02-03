#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyClass
{
public:
	MyClass( int paramter )
	{}
};

int main()
{
	MyClass anInstance( 42 );
	MyClass anotherIns { 69 };

	return 0;
}