#include <iostream>

int main()
{
    int age;
	std::cout << "What is your age?" << std::endl;
	std::cin >> age;
    if (age<5)
    {
      std::cout << "You're a baby" << std::endl;
    }
    else if (age >= 13 && age <= 18)
    {
      std:: cout << "You're a teenager" << std::endl;
    }
    if (age>=16)
    {
      std::cout << "You can drive" << std::endl;
    }
    if (age>=18)
    {
      std::cout << "You can vote" << std::endl;
    }

    return 0;
}