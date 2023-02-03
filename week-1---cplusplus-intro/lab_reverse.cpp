#include "lab_reverse.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> sequence { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	std::vector<int> reversed = reverse( sequence );

	std::cout << "original: ";
	for( int i=0; i<sequence.size(); ++i )
		std::cout << sequence[i] << ", ";
	std::cout << std::endl;

	std::cout << "reversed: ";
	for( int i=0; i<reversed.size(); ++i )
		std::cout << reversed[i] << ", ";
	std::cout << std::endl;

	return 0;
}
