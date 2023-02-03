#include "bankaccount.h"
#include <iostream>
      
int main()
{
  BankAccount a( "Bob" );

  std::cout << a.number << std::endl;

  BankAccount b( "Bankyaccount McBankaccountface" );

  /* static class attributes can be accessed either through an object
       i.e. b.number
     or through the class itself
       i.e. BankAccount::number */
  std::cout << b.number << std::endl; 
  std::cout << BankAccount::number << std::endl; 
  
  a.deposit( 100 );

  return 0;
}
