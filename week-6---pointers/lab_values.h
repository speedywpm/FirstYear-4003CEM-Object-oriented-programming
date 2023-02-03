#include <iostream>

int test( int value, int expected )
{
	if( value != expected )
	{
		std::cerr << "Error - value should be " << expected << " but it's " << value << " instead." << std::endl;
		return 1;
	}

	return 0;
}
#define TEST( EXPECT ) errors += test( variable, EXPECT );

int errors = 0;
int *pointerToVariable = &variable;
#pragma GCC poison variable
