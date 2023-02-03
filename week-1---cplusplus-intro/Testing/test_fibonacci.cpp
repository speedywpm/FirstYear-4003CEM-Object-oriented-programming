// nasty nasty hacks so can include and run student file with a main()
#define main studentmain
#include <lab_fibonacci.cpp>
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
#include <vector>
#include <regex>

std::vector<std::string> split(const std::string& input, const std::string& regex) 
{
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

SCENARIO( "Testing Fibonacci!" )
{
    CaptureStream cs( std::cout );
    cs.capture();
    student_main_runner();
    cs.release();

    const std::vector<std::string> expected { "0", "1", "1", "2", "3", "5", "8", "13", "21", "34", "55", 
                                              "89", "144", "233", "377", "610", "987", "1597", "2584", "4181" };
    std::vector<std::string> result = split( cs.str(), "\r{0,1}\n" );
    
    {
        INFO( "Test that the correct number of lines were printed." );
        if( cs.str().length() == 0 )
            FAIL( "Nothing was printed, did you use cout?" );
        
        if( result.size() != expected.size() )
        {
            std::stringstream ss;
            ss << "Wrong number of lines printed, expected " << expected.size()
                << " but got " << result.size() << " instead";
            FAIL( ss.str() );
        }
    }

    for( auto student=result.cbegin(), expecting=expected.cbegin();
         student != result.cend();
         student=next(student), expecting=next(expecting) )
    {
        std::stringstream ss;
        ss << "Check line " << std::distance(result.cbegin(),student)+1 
           << ", expecting " << *expecting << ", got " << *student;
        INFO( ss.str() );

        CHECK_THAT( *student, Catch::Contains( *expecting ) );
    }
}
