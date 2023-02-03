#include <array>
#include <iostream>
using namespace std;

int some_function( array<int,5> &values )
{
	for( int i=0; i<values.size(); ++i )
		values[i] *= 2;
}

int main()
{
	array<int,5> v {0, 1, 2, 3, 4};

	some_function(v);

	for( int i : v )		// 0,2,4,6,8
		cout << i << ",";
	cout << endl;

	return 0;
}