#include <lab_animal3.h>

#include "catch.hpp"
#include "captureio.h"

#include <sstream>
#include <string>
#include <iostream>

SCENARIO( "Flying" )
{
    // create a bird object
    Bird bird( "Tweety", "Yellow", true );

    CaptureStream cs( std::cout );    
    cs.capture();
    
    // call the flap() method, should print a message containing the word "flying"
    bird.flap();

    cs.release();

    const std::string expected = "flying";
    
    INFO( "Looking for \""+expected+"\"" );
    const std::string programOutput = cs.str();
    REQUIRE_THAT( programOutput, Catch::Contains( expected ) );
}
