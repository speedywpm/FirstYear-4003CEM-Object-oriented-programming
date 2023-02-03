#include <array>
#include <string>
#include <iostream>
using namespace std;

void test_int( int *ptr ) { cout << "An int takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_uint( unsigned int *ptr ) { cout << "An unsigned int takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_short( short *ptr ) { cout << "A short takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_char( char *ptr ) { cout << "A char takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_float( float *ptr ) { cout << "A float takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_double( double *ptr ) { cout << "A double takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_string( string *ptr ) { cout << "A string takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }
void test_array( array<int,10> *ptr ) { cout << "An array of 10 elements takes " << sizeof(*ptr) << " bytes but a pointer to one takes " << sizeof(ptr) << " bytes" << endl; }

