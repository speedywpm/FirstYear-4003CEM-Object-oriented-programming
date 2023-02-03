# 4003CEM-classes

## lab_ai3
Add one line of code to the end of `lab_ai3.cpp` that causes `secondAI` to also `say_hello`.

## lab_yourturn
Open aiyourturn.h. This starts off as a copy of the class from ai6.h. Edit this class to:
- Add a new class attribute called `usedNames`.  This should be an empty vector of strings declared just before the constructor (`AI()`) (method definition.
- Add to the constructor method the code need to add the new randomly picked name to the vector usedNames.
- Create a new class method called `who_is_here`.  The method does not have any input.  It simply has one line to return the `usedNames` vector.

## lab_rectangle
```
float get_side_1() const
{
    return side1;
}
```
Add this code into Rectangle.h and a second function for the other side.

## lab_yourturn 2
Open `aiyourturn.h`.  First change the object attribute `name` to private. 

Second, add a method `get_name()` which simply returns the name of the object.

Third, add an object method `set_name(newName)` for changing the name of an existing AI object.  The method should:
- Reassign `newName` to be an upper case version of itself.
- If `newName` is already in `usedNames` then the function should raise a `ValueError` because it is not possible to change to an already taken name.
- Otherwise: 
-- remove the original name from the `usedNames` class attribute; 
-- add `newName` to the `usedNames` list; 
-- and change `name` to the `newName`.

## lab_bankaccount
Create a new file called `BankAccount.h`.  Inside, define a class called `BankAccount` subject to the following requirements.

- Each object of the class should have the attributes `name` and private attribute `balance`.  `name` should be a string whilst `balance` should be a float.

- The instantiation method should require an argument  determining the customer's name.  It should automatically initialise the balance to zero.  

- Create a method `get_balance` which allows the user to obtain the balance of an account (but not edit it).

- Create two separate object methods called  `deposit` and `withdraw` for editing the balance (increase and decrease respectively).  Each method should take a positive number as input.  Make sure that `withdraw` does not allow the balance to become negative!

Test your class by creating two bank accounts and making some deposits and withdrawals.  When you are confident run the check below.

## lab_bankaccount 2
Extend your class as follows.

- Add a static attribute `number` and getter function `number_accounts` which keeps count of how many accounts have been created

## lab_bankaccount 3
- Write a method `transfer` which takes two bank accounts as input along with an amount.  It transfers that amount from the first bank account to the second (assuming there is enough money in the first).
As a hint for this function, make sure that you declare the parameter in the function header as `BankAccount &other`. The reasons for this will be covered in the pointers week.

## lab_bankaccount 4
Modify your `BankAccount` class so that the `number_accounts()` method will return the correct number even if accounts are closed.

## Advanced 
There is a **LOT** of additional features of C++ classes that it is not possible to cover within the scope of this module.

If you are after additional areas to investigate these are some suggestions.

- Operator overloading
  * Can you modify your BankAccount class so that you can add and subtract money from it using the += and -= operators?
  * Can you make is so that bank accounts can be printed using cout? (Hint: look at the `<<` operator).
		
```c++
BankAccount ba("Bob's account");
ba += 42;
ba -= 1;
// prints "Bob's account: £41.0"
std::cout << ba << std::endl;
```

- User defined conversion
  * Can you make it so that we can convert our bankaccount into a float?

```c++
BankAccount ba("Bob's account");
ba.deposit( 123 );

float balance = ba;
// prints 123.0
std::cout << balance << std::endl;