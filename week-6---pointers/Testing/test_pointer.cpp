// nasty nasty hacks so can include and run student file with a main()
#define main studentmain
#include <lab_pointer.cpp>
#undef main
template<typename R, typename I, typename C>
R student_main_runner( R(*func)(I, C) ) { return func(0,{}); }
template<typename R>
R student_main_runner( R(*func)() ) { return func(); }
int student_main_runner(){ return student_main_runner(studentmain); }
// end of nasty nasty hacks

#include <catch.hpp>
#include <captureio.h>

#include <iostream>
#include <sstream>
#include <algorithm>

TEST_CASE( "Check result", "[task]" )
{
    CaptureStream cs( std::cout );
    cs.capture();

    // run student code
    student_main_runner();

    cs.release();

    // get output of code and remove newlines
    const std::string response = cs.str();

    const std::vector< std::string > testStrings 
        {"An int takes 4 bytes but a pointer to one takes 8 bytes",
        "An unsigned int takes 4 bytes but a pointer to one takes 8 bytes",
        "A short takes 2 bytes but a pointer to one takes 8 bytes",
        "A char takes 1 bytes but a pointer to one takes 8 bytes",
        "A float takes 4 bytes but a pointer to one takes 8 bytes",
        "A double takes 8 bytes but a pointer to one takes 8 bytes",
        "A string takes 32 bytes but a pointer to one takes 8 bytes",
        "An array of 10 elements takes 40 bytes but a pointer to one takes 8 bytes"};
    
    for( auto &s : testStrings )
        REQUIRE_THAT( response, Catch::Contains( s ) );
}
