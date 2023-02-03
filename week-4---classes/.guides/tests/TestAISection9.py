#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from AIYourTurn import AI

print("")

try:
  AI1 = AI()
  AI2 = AI()
  AI3 = AI()
  AI4 = AI()
except:
  print("Error created when initialising AIs with AI()")
  print("Check your class name and init function.")
  sys.exit(1)

try:
  print(AI1.name)
  print("I was able to access the attribute name of an AI")
  print("It was not private!")
  sys.exit(1)
except AttributeError:
  pass  



try:
  oldName = AI1.getName()
except AttributeError:
  print("No method getName or running getName causes error!")
  print("Check your spelling!  Test your method!")
  print("Check method requires no input.")
  sys.exit(1)

newNameTaken = AI4.getName()
newNameFree = "ThisIsNotAName"

try:
  AI1.setName(newNameTaken)
except AttributeError:
  print("Method setName does not exit")
  print("Check Spelling!")
  sys.exit(1)
except ValueError:
  print("Correct error triggered by changing to taken name")

try:
  AI1.setName(newNameFree)
except:
  print("Changing to valid name caused exception")
  sys.exit(1)

try:
  used = AI.whoIsHere()  
except:
  print("Calling whoIsHere caused exception")
  sys.exit(1)

if not(newNameFree.upper() in used):
  print(used)
  print("output of whoIsHere does not have new name")
  sys.exit(1)
if oldName in used:
  print("output of whoIsHere still has old name")
  sys.exit(1)
  

print("All tests passed")
sys.exit(0)