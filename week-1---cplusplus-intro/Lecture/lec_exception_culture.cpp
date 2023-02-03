#include <iostream>
using namespace std;

int main()
{
    cout << "Fraction converter" << endl;
    float nom, denom;
    cin >> nom >> denom;

    if( denom != 0 )
    {  
        float decimal = nom / denom;
        cout << decimal << endl;
    }
    else
        cerr << "Denominator can't be 0" << endl;

    return 0;
}