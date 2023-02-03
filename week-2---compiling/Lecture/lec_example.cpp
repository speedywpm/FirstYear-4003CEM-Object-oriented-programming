#include <iostream>
using namespace std;

void print_two( int a, int b )
{
	cout << a << "+" << b 
		<< "=" << a+b << endl;
}

int main()
{
	print_two( 1, 2 );

	return 0;
}