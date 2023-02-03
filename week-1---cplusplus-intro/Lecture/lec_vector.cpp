#include <iostream>
#include <array>
#include <vector>
using namespace std;		
		
int main()
{
	array<int,5> myArray = {1,2,3,4,5};
	vector<int> myVector = {1,2,3,4};
	
	myVector.emplace_back(5);
	
	cout << myArray[0] << endl;
	cout << myVector[0] << endl;
}