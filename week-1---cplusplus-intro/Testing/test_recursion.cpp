#include <lab_recursion.h>

#include <catch.hpp>
#include <captureio.h>
#include <sstream>

SCENARIO( "It is a palindrome" )
{
    WHEN( "Even length word" )
    {
        REQUIRE( is_palindrome( "redder" ) == true );
    }

    WHEN( "Odd length word" )
    {
        REQUIRE( is_palindrome( "deified" ) == true );
        REQUIRE( is_palindrome( "civic" ) == true );
        REQUIRE( is_palindrome( "radar" ) == true );
        REQUIRE( is_palindrome( "level" ) == true );
        REQUIRE( is_palindrome( "rotor" ) == true );
        REQUIRE( is_palindrome( "kayak" ) == true );
        REQUIRE( is_palindrome( "reviver" ) == true );
        REQUIRE( is_palindrome( "racecar" ) == true );
        REQUIRE( is_palindrome( "madam" ) == true );
        REQUIRE( is_palindrome( "refer" ) == true );
    }

    WHEN( "Short word" )
    {
        REQUIRE( is_palindrome( "a") == true );
    }

    WHEN( "Long word" )
    {
        REQUIRE( is_palindrome("tattarrattat") == true );
    }

    GIVEN( "The function should return a boolean" )
    {
        auto result = is_palindrome( "wibble" );
        if( !std::is_same<decltype(result), bool>() )
            FAIL( "is_palindrome() does not return a boolean" );
    }
}

SCENARIO( "It is not a palindrome" )
{
    WHEN( "Even length word" )
    {
        REQUIRE( is_palindrome( "monkey" ) == false );
        REQUIRE( is_palindrome( "polymorphism" ) == false );
    }

    WHEN( "Odd length word" )
    {
        REQUIRE( is_palindrome( "apple" ) == false );
        REQUIRE( is_palindrome( "chair" ) == false );
        REQUIRE( is_palindrome( "wok" ) == false );
    }

    WHEN( "Short word" )
    {
        REQUIRE( is_palindrome( "hi" ) == false );
    }

    WHEN( "Long word" )
    {
        REQUIRE( is_palindrome("antidisestablishmentarianism") == false );
    }
}