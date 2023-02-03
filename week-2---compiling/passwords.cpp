#include "passwords.h"

int possible_combinations( int characters, int length )
{
    if( characters <= 0 || length <=0 )
        return 0;

    return pow( characters, length );
}

bool good_password( std::string password )
{
    int upper = 0, lower = 0, special = 0, digit = 0;
    const int goodThreshold = 1000000000;

    // count types of characters in password
    for( char c : password )
    {
        if     ( c >= 'A' && c <= 'Z' ) ++upper;    // is uppercase character
        else if( c >= 'a' && c <= 'z' ) ++lower;    // is lowercase character
        else if( c >= '0' && c <= '9' ) ++digit;    // is a number
        else                            ++special;
    }

    // how many characters need to be checked
    int characters = 0;
    if( upper ) characters += 26;
    if( lower ) characters += 26;
    if( digit ) characters += 10;
    if( special ) characters += 10;

    // good password if possible combinations > threshold
    return possible_combinations( characters, password.length() ) > goodThreshold;
}
