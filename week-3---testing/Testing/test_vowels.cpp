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
    }

}

