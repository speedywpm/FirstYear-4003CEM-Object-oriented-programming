#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from AIYourTurn import AI

print("")

try:
  org = AI.whoIsHere()
except AttributeError:
  print("Either no class method called whoIsHere")
  print("Or running whoIsHere causes AttributeError.")
  print("Check your spelling! Test your method!")
  print("Check method requires no input.")
  sys.exit(1)

try:
  AI1 = AI()
  AI2 = AI()
  AI3 = AI()
  AI4 = AI()
  print("")
except:
  print("Error created when initialising AIs with AI()")
  print("Check your class name and init function.")
  sys.exit(1)

ans = AI.whoIsHere()
if ans==None:
  print("The output of whoIsHere is None?")
  print("Check that you are not returning the output of sort")
  print("Sort is a modifier - so it edits a list and gives None as output.")
  sys.exit(1)

names = []
for obj in [AI1, AI2, AI3, AI4]:
  names.append(obj.name)
  if not( obj.name in ans ):
    print("AI name not getting added to output of whoIsHere?")
    sys.exit(1)

if set(ans) != set(names).union( set(org) ):
  print("Output of whoIsHere contains something other than AI names!")
  sys.exit(1)

names.sort()
if ans!=names:
  print("Output of whoIsHere has not been sorted into alphabetical order.")
  print("Its not hard - there is a list method to do this for you!")
  sys.exit(1)
  
print("All tests passed")
sys.exit(0)