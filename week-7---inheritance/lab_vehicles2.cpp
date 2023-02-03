#include "lab_vehicles2.h"

int main()
{
	LargeCar myCar;

	std::cout << "A LargeCar has " << myCar.wheels << " wheels." << std::endl;

	/* doesn't really make sense to have a seperate motor attribute with a 
		MotorisedVehicle class present. instead I'm going to ask if LargeCar
		inherits from MotorisedVehicle */
	std::cout << "Does a LargeCar have a motor? " << std::boolalpha 
		<< std::is_base_of<MotorisedVehicle,LargeCar>() << std::endl;

	return 0;
}