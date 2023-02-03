#include <lab_leap.h>

#include "catch.hpp"
#include "captureio.h"
#include <sstream>

SCENARIO( "Leap year testing", "[leap]" )
{
    WHEN( "A year is divisible by 4" )
    {
        THEN( "It is a leap year" )
            REQUIRE( is_leap(2004) == true );

        AND_WHEN("A year is divisible by 100 ")
        {
            THEN( "It is not a leap year" )
                REQUIRE( is_leap(1900) == false );

            AND_WHEN( "A year is divisible by 400" )
                THEN( "It is a leap year" )
                    REQUIRE( is_leap(2000) == true );
        }
    }        

    GIVEN( "The function should return a boolean" )
    {
        auto result = is_leap(2000);
        if( !std::is_same<decltype(result), bool>() )
            FAIL( "is_leap() does not return a boolean" );
    }
}

SCENARIO( "Exhaustive testing", "[exhaustive]" )
{
    for( int year=1600; year<=3000; ++year )
    {
        
        // deliberate gibberish so you can't just copy how I did it
        bool answer = (year*8)/4/2%(0xcb8+4136-0x1b50)==(0x943+3219-0x15d6) || 
            (year%(0xba5+2053-0x13a6)==(0x9dd+6591-0x239c) && 
            year%(0x197c+1645-0x1f85)!=(0x18a9+3620-0x26cd));

        bool result = is_leap( year );

        if( answer != result )
        {
            std::stringstream ss;
            ss << "is_leap( " << year << " ) returned " << ( result ? "true" : "false" ) 
                << " when it should have returned " << ( answer ? "true" : "false" ) << std::endl;
            FAIL( ss.str() );
        }        
    }
}