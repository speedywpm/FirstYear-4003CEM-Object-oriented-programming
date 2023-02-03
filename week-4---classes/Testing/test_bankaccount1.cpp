#include "bankaccount.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test Account" )
{
  GIVEN( "A BankAccount" )
  {
    const std::string expectedName = "Bob's account";
    BankAccount ba1( expectedName );

    REQUIRE( ba1.name == expectedName );
    REQUIRE( ba1.get_balance() == 0.f );

    WHEN( "Money is deposited" )
    {
      const float expectedBalance = 123.4f;
      ba1.deposit( expectedBalance );
      REQUIRE( ba1.get_balance() == expectedBalance );

      AND_THEN( "A negative amount of money is deposited" )
      {
        const float balanceBefore = ba1.get_balance();
        ba1.deposit( -1.f );
        REQUIRE( ba1.get_balance() == balanceBefore );
      }

      AND_THEN( "A negative amount of money is withdrawn" )
      {
        const float balanceBefore = ba1.get_balance();
        ba1.withdraw( -1.f );
        REQUIRE( ba1.get_balance() == balanceBefore );
      }

      AND_THEN( "Money is withdrawn" )
      {
        ba1.withdraw( 1.f );
        REQUIRE( ba1.get_balance() == expectedBalance-1.f );
      }

      AND_THEN( "Too much money is withdrawn" )
      {
        ba1.withdraw( ba1.get_balance()*2 );
        REQUIRE( ba1.get_balance() == expectedBalance );
      }
    }
  }  
}
