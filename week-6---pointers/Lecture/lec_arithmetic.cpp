#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int,4> myArray {69, 42, 99, 3};
	int *myPointer = myArray.data();

	cout << *myPointer << endl;
	myPointer += 1;
	cout << *myPointer << endl;
	myPointer += 2;
	cout << *myPointer << endl;

	return 0;
}
