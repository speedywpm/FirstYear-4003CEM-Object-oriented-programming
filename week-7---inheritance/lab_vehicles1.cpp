#include "lab_vehicles1.h"

int main()
{
	LargeCar myCar;

	std::cout << "A LargeCar has " << myCar.wheels << " wheels." << std::endl;
	std::cout << "Does a LargeCar have a motor? " << std::boolalpha << myCar.motor << std::endl;

	return 0;
}