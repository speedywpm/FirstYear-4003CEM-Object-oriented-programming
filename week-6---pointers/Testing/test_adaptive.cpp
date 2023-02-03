#include <lab_adaptive.h>

#include <catch.hpp>
#include <captureio.h>

#include <iostream>
#include <sstream>
#include <algorithm>

TEST_CASE( "Check result", "[task]" )
{
    CaptureStream cs( std::cout );
    InjectStream is( std::cin );

    std::vector<int> testValues;
    std::string matchRegex;
    std::stringstream ss;

    SECTION( "3 value test" )
    {
        testValues = { 111, 222, 333 };
        matchRegex = ".*333..*222..*111.*";
    }

    SECTION( "5 value test" )
    {
        testValues = { 42, 69, 99, 12, 3 };
        matchRegex = ".*3..*12..*99..*69..*42.*";
    }

    SECTION( "1 value test" )
    {
        testValues = { 345678 };
        matchRegex = ".*345678.*";
    }

    cs.capture();
    is.capture();

    // feed in the test data    
    is << testValues.size() << "\n";
    ss << "Testing with " << testValues.size() << " values: ";
    
    for( int i : testValues )
    {
        is << i << "\n";
        ss << i << ", ";
    }
    
    INFO( ss.str() );

    // run student code
    task();

    cs.release();
    is.release();

    // get output of code and remove newlines
    std::string response = cs.str();

    auto bad_char = [](char c){ return c=='\n' || c=='\r'; };
    response.erase( std::remove_if( response.begin(), response.end(), bad_char ), response.end() );

    // check for entered numbers in right order
    REQUIRE_THAT( response, Catch::Matches( matchRegex ) );    
}
