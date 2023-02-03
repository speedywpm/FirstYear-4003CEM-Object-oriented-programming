#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')

from BankAccount import BankAccount

try:
  startC = BankAccount.number
except AttributeError:
  print("Could not find public class attribute called number")
  sys.exit(1)

try: 
  ba1 = BankAccount("Bob")
  ba2 = BankAccount("Alice")
except:
  print("Exception caused initialising BankAccount using:")
  print("BankAccount('Bob')")
  print("Check your __init__ method!")
  sys.exit(1)

endC = BankAccount.number

if (endC-startC)!=2:
  print("class attribute number not increasing with number of accounts")
  
print("Tests on number passed")
sys.exit(0)