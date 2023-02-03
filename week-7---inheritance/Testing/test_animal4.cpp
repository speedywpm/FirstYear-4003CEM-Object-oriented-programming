#include <lab_animal4.h>

#include "catch.hpp"
#include "captureio.h"

#include <sstream>
#include <string>
#include <iostream>

TEST_CASE( "Flying bird" )
{
    // create a bird object
    Bird bird( "Tweety", "Yellow", true );

    CaptureStream cs( std::cout );    
    cs.capture();
  
    // call the display() method
    bird.display();

    cs.release();

    const std::string expected = "flying";
    
    INFO( "Looking for \""+expected+"\"" );
    const std::string displayOutput = cs.str();
    REQUIRE_THAT( displayOutput, Catch::Contains( expected ) );
}

TEST_CASE( "Flightless bird" )
{
    // create a bird object
    Bird bird( "Emu", "Grey", false );

    CaptureStream cs( std::cout );    
    cs.capture();
  
    // call the display() method
    bird.display();

    cs.release();

    const std::string expected = "flightless";
    
    INFO( "Looking for \""+expected+"\"" );
    const std::string displayOutput = cs.str();
    REQUIRE_THAT( displayOutput, Catch::Contains( expected ) );
}
