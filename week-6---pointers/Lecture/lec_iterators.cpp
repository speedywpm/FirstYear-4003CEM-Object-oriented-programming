#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<int,4> myArray {69, 42, 99, 3};
	
	// stepping through an array with a pointer
	for(int *ptr=myArray.data(); ptr<myArray.data()+myArray.size(); ptr+=1)
		cout << *ptr << endl;

	// stepping through an array with an iterator
	for(array<int,4>::iterator it=begin(myArray); it!=end(myArray); it=next(it))
		cout << *it << endl;

	// shorter way of writing the iterator code
	for(auto it=begin(myArray); it!=end(myArray); it=next(it))
		cout << *it << endl;

	return 0;
}