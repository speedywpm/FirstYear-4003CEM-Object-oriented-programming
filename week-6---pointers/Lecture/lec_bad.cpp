#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int,4> myArray {69, 42, 99, 3};
	int *myPtr = myArray.data();

	for( int i=0; i<=myArray.size(); ++i )
	{
		cout << *myPtr << endl;
		myPtr += 1;
	}

	return 0;
}