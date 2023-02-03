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
  b1 = ba1.getBalance()
  b2 = ba2.getBalance()  
except AttributeError:
  print("Could not call getBalance?")
  print("Check spelling and method definition.")
  sys.exit(1)

if b1!=0 or b2!=0:
  print("Balance not initialsed to zero.")
  print("Check __init__ method")
  sys.exit(1)

try:
  ba1.deposit(100)
except AttributeError:
  print("Could not use deposit method without error")
  sys.exit(1)

b1 = ba1.getBalance()  
if b1!=100:
  print("Deposited 100 but getBalance states balance is...")
  print(b1)
  sys.exit(1)

try:
  ba1.transfer(ba2, 60)
except AttributeError:
  print("Could not use transfer method")
  print("Check spelling and argument order")
  sys.exit(1)

b1 = ba1.getBalance()
b2 = ba2.getBalance()
if b1!=40:
  print("Method transfer did not update balance of first account correctly")
  sys.exit(1)
if b2!=60:
  print("Method transfer did not update balance of second account correctly")
  sys.exit(1)

ba1.transfer(ba2, 50)
b1 = ba1.getBalance()  
if b1<0:
  print("Method transfer transferred more money than first account had!")
  sys.exit(1)

print("Transfer tests all passed")
sys.exit(0)