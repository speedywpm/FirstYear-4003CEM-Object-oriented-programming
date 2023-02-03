#include <array>
#include <iostream>

class ReallyBigClass
{
public:
	std::array<int,100> bigArray;
	std::array<int,10000> massiveArray;
};

int task()
{
	ReallyBigClass var;
	ReallyBigClass *ptr = new ReallyBigClass;

	std::cout << "Size of var is " << sizeof(var) << " bytes" << std::endl;
	std::cout << "Size of ptr is " << sizeof(ptr) << " bytes but it's pointing at " << sizeof(*ptr) << " bytes" << std::endl;
  delete ptr;
	return 0;
}