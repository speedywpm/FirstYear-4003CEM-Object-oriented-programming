/* Include the unit testing libraries */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>

/* Include the code that we plan to test */
#include "lab_tax.h"

struct Test { int salary; int tax; };

TEST_CASE("Personal allowance tests")
{
    const std::vector<Test> tests { {0,11500},
                                    {9000,11500},
                                    {36000,11500},
                                    {100000,11500},
                                    {100001,11500},
                                    {115000,4000},
                                    {121100,950},
                                    {122905,48},
                                    {123000,0},
                                    {1000000,0} };

    for( auto test : tests )
        REQUIRE( personal_allowance(test.salary) == test.tax );
  WHEN("should be less than 11500")
  {
    REQUIRE(personal_allowance(10000) == 11500);
  }
}

TEST_CASE("Income tax tests")
{
    const std::vector<Test> tests { {9000,0},
                                    {11000,0},
                                    {16000,900},
                                    {31785,4057},
                                    {36000,4900},
                                    {42385,6177},
                                    {60000,13000},
                                    {100000,29000},
                                    {110000,35000},
                                    {1000000,436100} };

    for( auto test : tests )
        REQUIRE( income_tax(test.salary) == test.tax );
  
}
