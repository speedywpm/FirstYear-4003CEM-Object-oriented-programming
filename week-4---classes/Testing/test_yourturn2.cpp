#include "aiyourturn.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test getter and setters" )
{
	GIVEN( "A pair of AIs" )
	{
		AI a;
		AI b;
		
		std::vector<std::string> names = AI::who_is_here();

		WHEN( "Using a getter to read AI name" )		
		{
			REQUIRE( std::find( begin(names), end(names), a.get_name() ) != end(names) );
			REQUIRE( std::find( begin(names), end(names), b.get_name() ) != end(names) );
		}
		
		WHEN( "Using a setter to change an AI name" ) 
		{
			a.set_name("MCFAKEFACE");
			REQUIRE( a.get_name() == "MCFAKEFACE" );
		}

		WHEN( "Setting a name already in use" )
		{
			const std::string existingName = a.get_name();
			REQUIRE_THROWS_AS( a.set_name(existingName), std::invalid_argument );
		}	
	}
}
