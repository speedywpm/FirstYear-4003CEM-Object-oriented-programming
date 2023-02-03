#include <lab_even.h>

#include <catch.hpp>
#include <captureio.h>
#include <sstream>

SCENARIO( "Odd/even testing", "[leap]" )
{
    WHEN( "A number is even" )
    {
        REQUIRE( is_even(2) == true );
        REQUIRE( is_even(4) == true );
        REQUIRE( is_even(8) == true );
        REQUIRE( is_even(10) == true );

        REQUIRE( is_even(-2) == true );
        REQUIRE( is_even(0) == true );
    }

    WHEN( "A number is odd" )
    {
        REQUIRE( is_even(1) == false );
        REQUIRE( is_even(3) == false );
        REQUIRE( is_even(5) == false );
        REQUIRE( is_even(7) == false );

        REQUIRE( is_even(-1) == false );
    }

    GIVEN( "The function should return a boolean" )
    {
        auto result = is_even(2);
        if( !std::is_same<decltype(result), bool>() )
            FAIL( "is_even() does not return a boolean" );
    }
}

SCENARIO( "Big number testing" )
{
    constexpr int bigOdd = std::numeric_limits<int>::max();
    constexpr int bigEven = bigOdd-1;
    std::stringstream ss;

    WHEN( "A number is even" )
    {
        ss << "is_even(" << bigEven << ") should return true";
        if( !is_even( bigEven ) )
            FAIL( ss.str() );
    }

    WHEN( "A number is odd" )
    {
        ss << "is_even(" << bigOdd << ") should return true";
        if( is_even( bigOdd ) )
            FAIL( ss.str() );
    }
}

SCENARIO( "Exhaustive testing", "[exhaustive]" )
{
    for( int number=-100; number<=100; ++number )
    {
        // deliberate gibberish so you can't just copy how I did it
        bool answer = ((number%int('A'-'?'))==int(0x55&0xAA))&~0x00000000;

        bool result = is_even( number );

        if( answer != result )
        {
            std::stringstream ss;
            ss << "is_even( " << number << " ) returned " << ( result ? "true" : "false" ) 
                << " when it should have returned " << ( answer ? "true" : "false" ) << std::endl;
            FAIL( ss.str() );
        }        
    }
}