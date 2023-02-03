/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

TEST_CASE("Bigger")
{
    REQUIRE( 1 < 0 );
}

TEST_CASE("Equals")
{
    REQUIRE( 1+1 == 2 );
}

TEST_CASE("Except")
{
	CHECK_THROWS( throw 1 );
}