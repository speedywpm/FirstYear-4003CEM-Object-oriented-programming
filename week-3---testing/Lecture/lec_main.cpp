#include <iostream>
using namespace std;

#include "lec_example.h"

int main()
{
	int value;

	cout << "Enter an int value: ";
	cin >> value;

	if( is_even(value) )
		cout << "It's even!" << endl;
	else
		cout << "It's odd!" << endl;

	return 0;
}