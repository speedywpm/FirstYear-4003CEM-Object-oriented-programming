#include <iostream>
#include "rectangle.h"

int main()
{
	Rectangle r1( 3, 4 );
  
	std::cout << r1.perimeter() << ", " << r1.area() << std::endl;

	r1.scale( 3 );
	
	std::cout << r1.perimeter() << ", " << r1.area() << std::endl;

    return 0;
  std::cout << r1.side1 << ", " << r1.side2 << std::endl;
}
