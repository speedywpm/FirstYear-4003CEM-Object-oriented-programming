#include <iostream>
#include <stdexcept>
using namespace std;

class Negative: public runtime_error
{
public:
	Negative() : runtime_error("Can't have a negative factorial") 
	{}
};

int factorial( int n )
{
	if( n < 0 ) throw Negative();
	else if( n == 0 ) return 1;

	return n * factorial(n-1);
}

int main()
{
	try
	{   
		cout << factorial( 5 ) << endl;
		cout << factorial( -8 ) << endl;
	}
	catch( Negative& e )
	{
		cerr << e.what() << endl;
	}

	return 0;
}
