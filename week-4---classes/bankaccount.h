#include <iostream>

class BankAccount
{
public:
    std::string name;
private:
    float balance;

    INSTANTIATION( string name, float balance)
    {
        std::cout << name << std::endl;
        balance=0;
    }
    deposit( float balance )
    {
        if(deposit()>0)
          balance=balance+deposit();
    }
    withdraw( float balance )
    {
        if(balance>0 && withdraw()>0 && withdraw()<balance)
          balance=balance-withdraw();
    }
    void get_balance() const
    {
        return balance;
    }
    
    
}