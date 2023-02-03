#!/usr/bin/python3
import sys
from io import StringIO
sys.path.insert(0, '/home/codio/workspace')

from Animal3 import *
myA = Bird("Iago", "Red", True)
try:
  myA = Bird("Iago", "Red", True)
except:
  print("Could not initialise an instance of Bird class.")
  print("Check spelling of class and remembered underscores in __init__")
  print("Check init has 4 parameters: object, name, colour and canFly boolean (in that order)")
  sys.exit(1)

try: 
  if myA.canFly != True:
    print("canFly not initialised correctly")
    sys.exit(1)
except:
  print("Exception caused accessing canFly attribute.")
  print("Ensure it is public and check spelling.")
  sys.exit(1)

old_stdout = sys.stdout
mystdout = StringIO()
sys.stdout = mystdout
try: 
  myA.flap()
except:
  print("Exception caused calling flap method on bird that can fly.")
  print("Check spelling.")
  sys.exit(1)
sys.stdout = old_stdout  
printed =  mystdout.getvalue()
if not( "flying" in printed ):
  print("Ran flap method on Bird that can fly but...")
  print("... message printed did not contain the word 'flying'!")
  sys.exit(1)

old_stdout = sys.stdout
mystdout = StringIO()
sys.stdout = mystdout 
myP = Bird("Pingu", "Black", False) 
try: 
  myP.flap()
except:
  print("Exception caused calling flap method on bird that cant fly.")
  print("Check spelling.")
  sys.exit(1)
sys.stdout = old_stdout  
printed =  mystdout.getvalue()
if "flying" in printed:
  print("Ran flap method on Bird that can NOT fly but...")
  print("... message printed still contained the word 'flying'!")
  sys.exit(1)
  
  
print("Tests all passed")
sys.exit(0)