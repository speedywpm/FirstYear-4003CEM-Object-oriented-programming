// nasty nasty hacks so can include and run student file with a main()
#define main studentmain
#include <lab_welcome.cpp>
#undef main
template<typename R, typename I, typename C>
R student_main_runner( R(*func)(I, C) ) { return func(0,{}); }
template<typename R>
R student_main_runner( R(*func)() ) { return func(); }
int student_main_runner(){ return student_main_runner(studentmain); }
// end of nasty nasty hacks

#include "catch.hpp"
#include "captureio.h"

#include <sstream>
#include <string>
#include <iostream>

SCENARIO( "Testing Welcome!", "[welcome]" )
{
    CaptureStream cs( std::cout );
    cs.capture();
    student_main_runner();
    cs.release();

    const std::string expected = "Welcome to 4003CEM!";
    
    INFO( "Looking for \""+expected+"\"" );
    REQUIRE_THAT( cs.str(), Catch::Contains( expected ) );
}
