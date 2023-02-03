/* Include the unit testing libraries */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

/* Include the code that we plan to test */
#include "lab_age.h"

/** general test cases where we hard code a few specifc values **/
TEST_CASE( "Babies" )
{
    std::string expectedAnswer = "baby";

    // testing a general value
    REQUIRE( age_description(3) == expectedAnswer );

    // making sure that the minimum and maximum of the range are correct
    REQUIRE( age_description(0) == expectedAnswer );
    REQUIRE( age_description(4) == expectedAnswer );

    // making sure that just outside the min and max of the range is correct
    REQUIRE( age_description(-1) != expectedAnswer );
    REQUIRE( age_description(5) != expectedAnswer );
}

/** of course we could check every single possible value, but this isn't 
 * going to be an option in most cases as we might have to check
 * billions of possible values which isn't realistic **/
TEST_CASE( "Children" )
{
    const std::string expectedAnswer = "child";
    const int minimum = 5;
    const int maximum = 12;
    
    WHEN( "Is a child, 5 to 12 years")
    {
        for( int test=minimum; test<=maximum; ++test )
        {
            REQUIRE( age_description(test) == expectedAnswer );
        }
    }

    WHEN( "Is not a child edge cases" )
    {
        // making sure that just outside the min and max of the range is correct
        REQUIRE( age_description(minimum-1) != expectedAnswer );
        REQUIRE( age_description(maximum+1) != expectedAnswer );
    }
}

/** We could make things easier by specifying the limits of the range
 * and then basing everything off those variables **/
TEST_CASE( "Teenagers" )
{
    const std::string expectedAnswer = "teenager";
    const int minimum = 13;
    const int maximum = 19;

    WHEN( "Is a teenager" )
    {
        // testing a general value
        REQUIRE( age_description(15) == expectedAnswer );

        // making sure that the minimum and maximum of the range are correct
        REQUIRE( age_description(minimum) == expectedAnswer );
        REQUIRE( age_description(maximum) == expectedAnswer );
    }

    WHEN( "Is not a teenager edge cases" )
    {
        // making sure that just outside the min and max of the range is correct
        REQUIRE( age_description(minimum-1) != expectedAnswer );
        REQUIRE( age_description(maximum+1) != expectedAnswer );
    }
}

/** Unit tests like this can also act as documentation for your code,
 * the tests include all the information needed to implement 
 * behaviours and features even if they have initially been left out of
 * the code **/
TEST_CASE( "Liars" )
{
    const std::string expectedAnswer = "lying";

    // test the edges
    REQUIRE( age_description(-1) == expectedAnswer );
    REQUIRE( age_description(123) == expectedAnswer );

    // test generally bonkers values
    REQUIRE( age_description(-123456) == expectedAnswer );
    REQUIRE( age_description(123456) == expectedAnswer );
}

/** And the Catch2 unit testing framework will allow use to write 
 * tests so that they give nice descriptive messages if they fail **/
TEST_CASE( "Adults" )
{
    const std::string expectedAnswer = "adult";
    const int minimum = 20;
    const int maximum = 64;

    WHEN( "The person is an adult" )
    {
        REQUIRE( age_description(42) == expectedAnswer );

        AND_WHEN( "They have just become one" )
        {
            REQUIRE( age_description(minimum) == expectedAnswer );
        } 

        AND_WHEN( "They are about to stop being one" )
        {
            REQUIRE( age_description(maximum) == expectedAnswer );
        }
    }

    WHEN( "They are not an adult edge cases" )
    {
        REQUIRE( age_description(minimum-1) != expectedAnswer );
        REQUIRE( age_description(maximum+1) != expectedAnswer );
    }
}

TEST_CASE( "OAPs" )
{
    const std::string expectedAnswer = "oap";
    const int minimum = 65;
    const int maximum = 122;

    // testing a general value
    REQUIRE( age_description(83) == expectedAnswer );

    // making sure that the minimum and maximum of the range are correct
    REQUIRE( age_description(minimum) == expectedAnswer );
    REQUIRE( age_description(maximum) == expectedAnswer );

    // making sure that just outside the min and max of the range is correct
    REQUIRE( age_description(minimum-1) != expectedAnswer );
    REQUIRE( age_description(maximum+1) != expectedAnswer );
}


