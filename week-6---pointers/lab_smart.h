#include "input.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <memory>

int task()
{
	int size = 0;

	// get the size
	while( size <= 0 )
	{
		std::cout << "Enter a size: ";
		try
		{
			size = input<int>(); // using my function for getting input
		}
		catch( std::runtime_error &e )
		{
			std::cerr << "Not an integer" << std::endl;
		}
	}

	std::cout << "Reading in " << size << " values." << std::endl;

	// COMPLETE ME

	return 0;
}