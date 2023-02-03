#include "bankaccount.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test Account" )
{
  GIVEN( "A BankAccount" )
  {
    BankAccount ba1( "Account 1" );

    const float expectedBalance = 456.7f;
    ba1.deposit( expectedBalance );
    REQUIRE( ba1.get_balance() == expectedBalance );
    
    GIVEN( "A second bank account" )
    {
      BankAccount ba2( "Account 2" );

      WHEN( "Money is transfered between accounts" )
      {
        ba1.transfer( ba2, 1.f );
        REQUIRE( ba1.get_balance() == expectedBalance-1.f );
        REQUIRE( ba2.get_balance() == 1.f );
      }

      WHEN( "A negative amount of money is transfered" )
      {
        const float balanceBefore1 = ba1.get_balance();
        const float balanceBefore2 = ba2.get_balance();
        ba1.transfer( ba2, -1.f );
        REQUIRE( ba1.get_balance() == balanceBefore1 );
        REQUIRE( ba2.get_balance() == balanceBefore2 );
      }
    }
  }  
}
