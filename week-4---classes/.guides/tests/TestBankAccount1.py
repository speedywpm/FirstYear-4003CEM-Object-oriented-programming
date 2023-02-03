#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')

from BankAccount import BankAccount

try: 
  ba1 = BankAccount("Bob")
  ba2 = BankAccount("Alice")
except:
  print("Exception caused initialising BankAccount using:")
  print("BankAccount('Bob')")
  print("Check your __init__ method!")
  sys.exit(1)

try:
  if ba2.name != "Alice":
    print("name was not assigned correctly to init input?")
except AttributeError:
  print("Could not find public object attribute name!")
  sys.exit(1)

try:
  b = ba1.balance
  print("Balance was not private as instructed!")
  sys.exit(1)
except AttributeError:
  pass

try:
  b = ba1.getBalance()
except AttributeError:
  print("Could not call getBalance without error.")
  print("Check spelling and method definition.")
  sys.exit(1)

if b!=0:
  print("Balance not initialsed to zero.")
  print("Check __init__ method")
  sys.exit(1)

try:
  ba1.deposit(100)
except AttributeError:
  print("Could not use deposit method without error")
  sys.exit(1)

b = ba1.getBalance()  
if b!=100:
  print("Deposited 100 but getBalance states balance is...")
  print(b)
  sys.exit(1)

try:
  ba1.withdraw(60)
except AttributeError:
  print("Could not use withdraw method")
  sys.exit(1)

b = ba1.getBalance()  
if b!=40:
  print("Deposited 100 and withdraw 60 but getBalance states balance is...")
  print(b)
  sys.exit(1)

ba1.withdraw(50)
b = ba1.getBalance()  
if b<0:
  print("Withdraw allowed be to take out more money than there is!")
  sys.exit(1)


print("Tests all passed")
sys.exit(0)