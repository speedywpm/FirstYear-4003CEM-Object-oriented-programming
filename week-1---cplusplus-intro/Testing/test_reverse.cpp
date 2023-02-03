#include <lab_reverse.h>

#include "catch.hpp"
#include <random>
#include <vector>
#include <algorithm>

void validate( const std::vector<int> &sequence )
{
    std::vector<int> studentResponse = reverse( sequence );

    {
        INFO( "Must be the same size" )
        REQUIRE( sequence.size() == studentResponse.size() );
    }

    auto it = studentResponse.begin();
    auto rt = sequence.rbegin();

    INFO( "Check values are reversed" )
    for( ; it!=studentResponse.end(); std::advance(it,1), std::advance(rt,1) )
    {
        REQUIRE( *it == *rt );
    }    
}

SCENARIO( "Short sequence", "[short]" )
{
    std::vector<int> sequence { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };;

    validate( sequence );
}

SCENARIO( "Long sequence", "[long]" )
{
    std::vector<int> sequence( 100 );
    for( auto it=sequence.begin(); it!=sequence.end(); advance(it,1) )
        *it = distance( sequence.begin(), it );

    validate( sequence );
}

SCENARIO( "Random sequence", "[random]" )
{
    std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> random_int;

    std::vector<int> sequence( 10 );
    for( auto it=sequence.begin(); it!=sequence.end(); advance(it,1) )
        *it = random_int(mt);

    validate( sequence );
}
