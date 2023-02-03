#include <lab_animal5.h>

#include "catch.hpp"
#include "captureio.h"

#include <sstream>
#include <string>
#include <iostream>

TEST_CASE( "Can cout an Animal" )
{
    Animal a( "Tweety", "Bird", "Yellow" );

    // "print" to a string
    std::stringstream ss;
    ss << a;

    const std::string coutOutput = ss.str();

    for( const std::string& expected : {"Yellow","Bird","Tweety"} )
    {
        INFO( "Looking for \""+expected+"\"" );
        REQUIRE_THAT( coutOutput, Catch::Contains( expected ) );
    }
}

TEST_CASE( "Can cout a Dog" )
{
    Dog a( "Gnasher", "Grey", false );

    // "print" to a string
    std::stringstream ss;
    ss << a;

    const std::string coutOutput = ss.str();

    for( const std::string& expected : {"Gnasher","Dog","Grey","unfriendly"} )
    {
        INFO( "Looking for \""+expected+"\"" );
        REQUIRE_THAT( coutOutput, Catch::Contains( expected ) );
    }
}

TEST_CASE( "Can cout a Bird" )
{
    Bird a( "Tweety", "Yellow", true );

    // "print" to a string
    std::stringstream ss;
    ss << a;

    const std::string coutOutput = ss.str();

    for( const std::string& expected : {"Tweety","Yellow","Bird","flying"} )
    {
        INFO( "Looking for \""+expected+"\"" );
        REQUIRE_THAT( coutOutput, Catch::Contains( expected ) );
    }
}