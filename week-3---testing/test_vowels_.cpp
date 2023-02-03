/* Include the unit testing libraries */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

/* Include the code that we plan to test */
#include "lab_vowels.h"

/** Complete the provided test case and add any additional ones that are required
 * to fully test the count_vowels() function **/
TEST_CASE( "Normal words" )
{
    WHEN( "All lowercase" )
    {
        REQUIRE( count_vowels("hello") == 2 );
        REQUIRE( count_vowels("antidisestablishmentarianism") == 11 );
    }

    WHEN( "All uppercase" )
    {
        REQUIRE( count_vowels("hello") == 2 );
        REQUIRE( count_vowels("antidisestablishmentarianism") == 11 );
    }

    WHEN( "A mixture of upper and lowercase" )
    {
        REQUIRE( count_vowels("HeLlO") == 2 );
        REQUIRE( count_vowels("AnTiDiSeStAbLiShMeNtArIaNiSm") == 11 );
    }

    WHEN( "There is a y in the word" )
    {
        REQUIRE( count_vowels("Holiday") == 3 );
        REQUIRE( count_vowels("MAYDAY") == 2 );
    }
}

TEST_CASE( "Odd words" )
{
    WHEN( "Letters and numbers" )
    {
        REQUIRE( count_vowels("h3ll0") == 0 );
        REQUIRE( count_vowels("ant1d1s3st4blishment4r1anism") == 5 );
    }
}

TEST_CASE( "Weird cases" )
{
    WHEN( "Nothing" )
    {
        REQUIRE( count_vowels("") == 0 );
    }

    WHEN( "No letters" )
    {
        REQUIRE( count_vowels("1234567890-=*&£^$&!£" ) == 0 );
        REQUIRE( count_vowels(" \t") == 0 );
    }
}
