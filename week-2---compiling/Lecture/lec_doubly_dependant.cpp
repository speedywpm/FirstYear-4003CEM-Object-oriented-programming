#include <iostream>
using namespace std;

void function1( int counter )
{
    if( counter == 0 ) return;

    cout << "This is a function 1" << endl;
    function2( counter-1 );
}

void function2( int counter )
{
    if( counter == 0 ) return;

    cout << "This is a function 2" << endl;
    function1( counter-1 );
}

int main()
{
    function1(5);

    return 0;
}