#include "bankaccount.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test Account" )
{
  REQUIRE( BankAccount::number_accounts() == 0 );

  GIVEN( "A BankAccount" )
  {
    BankAccount ba1( "Account 1" );
    REQUIRE( BankAccount::number_accounts() == 1 );

    GIVEN( "Another BankAccount" )
    {
      BankAccount ba2( "Account 2" );
      REQUIRE( BankAccount::number_accounts() == 2 );
    }
  }
}
