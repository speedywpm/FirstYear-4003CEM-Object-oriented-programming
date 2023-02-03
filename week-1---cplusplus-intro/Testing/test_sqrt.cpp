#include <lab_sqrt.h>

#include <catch.hpp>
#include <captureio.h>
#include <sstream>

SCENARIO( "Sqrt values" )
{
    const std::vector<float> tests {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1234};

    for( float test : tests )
    {
        const float myAnswer = my_sqrt( test );
        const float answer = sqrt( test );
        const bool inRange = abs( myAnswer - answer ) < 0.001;

        std::stringstream ss;
        ss << "my_sqrt( " << test << " ) should return a value of almost " << answer;
        INFO( ss.str() );
        REQUIRE( inRange );        
    }
}
