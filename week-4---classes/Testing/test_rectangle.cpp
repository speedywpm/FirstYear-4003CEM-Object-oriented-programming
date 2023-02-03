#include "rectangle.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test Rectangle" )
{

  GIVEN( "A Rectangle of known size" )
  {
    Rectangle rect( 42, 69 );

    const float expectedArea = 42*69;
    REQUIRE( rect.area() == expectedArea );

    {
      INFO( "Check get side functions" )
      REQUIRE( rect.get_side_1() == 42 );
      REQUIRE( rect.get_side_2() == 69 );
    }

    WHEN( "Rectangle is scaled" )
    {
      rect.scale( 2 );
      REQUIRE( rect.area() == expectedArea*4 );
    }
  }  
}
