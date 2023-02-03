#include <iostream>
#include <array>
using namespace std;		
		
int main()
{
	int oldArray[5] = {1,2,3,4,5};
	array<int,5> newArray = {1,2,3,4,5};		// use me!
	
	cout << oldArray[0] << " " << newArray[0] << endl;	
}