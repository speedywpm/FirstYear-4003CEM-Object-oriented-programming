int variable = 123456789;

#include "lab_values.h"
#include <iostream>

int main()
{
    int *ptr = pointerToVariable;  

	/* Change the value of "variable" to be 42, 
    BUT you aren't allowed to write anything like
	    variable = 42;
	you've got to use the pointer "ptr" */

    // COMPLETE ME

	TEST( 42 ); 
    /* Change the value of "variable" to be 69, 
    BUT you aren't allowed to write anything like
	    variable = 69;
	you've got to use pointer "ptr" */

    // COMPLETE ME

    TEST( 69 );
	/* Change the value of "variable" to be 999, 
    BUT you aren't allowed to write anything like
	    variable = 999;
	you've got to use pointer "ptr" */

    // COMPLETE ME

	TEST( 999 );
	std::cout << errors << " error/s" << std::endl;
	return errors;
}