#include "bankaccount.h"

#include <catch.hpp>

#include <vector>
#include <string>
#include <memory>

SCENARIO( "Test Account" )
{
  std::vector< std::unique_ptr<BankAccount> > accounts;

  REQUIRE( BankAccount::number_accounts() == 0 );

  GIVEN( "Multple accounts have been created" )
  {
    while( accounts.size() < 10 )
    {
      // create an account and check number is correct
      accounts.emplace_back( std::make_unique<BankAccount>( "Generic account" ) );
      REQUIRE( BankAccount::number_accounts() == accounts.size() );
    }

    AND_THEN( "Some accounts have been closed" )
    {
      while( !accounts.empty() )
      {
        // remove an account and check number is correct
        accounts.pop_back();
        REQUIRE( BankAccount::number_accounts() == accounts.size() );
      }
    }
  }
}
