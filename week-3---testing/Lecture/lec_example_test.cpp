/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

/* Include the code that we plan to test */
#include "lec_example.h"

TEST_CASE("Even tests")
{
	REQUIRE( is_even(2) == true );
	REQUIRE( is_even(2147483646) == true );
	REQUIRE( is_even(0) == true );
}

TEST_CASE("Odd tests")
{
	REQUIRE( is_even(1) == false );
	REQUIRE( is_even(2147483647) == false );
}