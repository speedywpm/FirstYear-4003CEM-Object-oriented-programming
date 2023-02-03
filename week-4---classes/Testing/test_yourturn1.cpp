#include "aiyourturn.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

TEST_CASE( "Test who_is_here function" )
{
  std::vector< std::unique_ptr<AI> > ais( 10 );
  for( auto &i : ais )
    i = std::make_unique<AI>();
 
  std::vector<std::string> names = AI::who_is_here();
   
  std::cout << "who_is_here(): ";
  for( auto &n : names ) std::cout << n << ", "; std::cout << std::endl;
  
  for( auto &i : ais )
  {
    INFO( "Looking for "+i->name+" in results returned by who_is_here()." );
    REQUIRE( std::find( begin(names), end(names), i->name ) != end(names) );
  } 
}
