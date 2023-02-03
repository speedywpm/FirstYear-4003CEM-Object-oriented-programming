#include "lab_pointer.h"

#include <array>
#include <string>

int main()
{
	int myInt = 1;
	unsigned int myUInt = 2;
	short myShort = 3;
	char myChar = 'A';
	float myFloat = 1.23;
	double myDouble = 2.31;
	std::string myString = "hello";
	std::array<int,10> myArray {1,2,3,4,5,6,7,8,9,10};

	test_int( int * myInt );
	test_uint( unsigned int * myUInt );
	test_short( short * myShort );
	test_char( char * myChar );
	test_float( float * myFloat );
	test_double( double * myDouble );
	test_string( std::string * myString );
	test_array( std::array<int,10> * myArray );

	return 0;
}
