#include "lab_even.h"

#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;  // get user input

    if( is_even( number ) )
        cout << "The number is even" << endl;
    else
        cout << "The number is uneven" << endl;

    return 0;
}