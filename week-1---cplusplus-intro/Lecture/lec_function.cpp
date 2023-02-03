#include <iostream>
using namespace std;

int sum( int a, int b )
{
	return a + b;
}

void nothing_function()
{
	cout << "Return nothing" << endl;
} 

int main()
{
	sum( 1, 2 );
	nothing_function();
}
