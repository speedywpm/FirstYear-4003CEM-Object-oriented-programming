#include <iostream>
#include <array>
using namespace std;

void some_function( array<int,5> values )
{
	for( int i=0; i<values.size(); ++i )
		values[i] *= 2;
}		

int main()
{
	array<int,5> v {0, 1, 2, 3, 4};

	for( int i : v )		// 0,1,2,3,4
		cout << i << ",";
	cout << endl;

	some_function(v);
	for( int i : v )		// 0,1,2,3,4
		cout << i << ",";
	cout << endl;
}