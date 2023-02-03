#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from AIYourTurn import AI

print("")

try:
  print(AI.usedNames)
  print("I was able to access the attribute usedNames (above)")
  print("It was not private!")
  sys.exit(1)
except AttributeError:
  pass
  
try:
  org = AI.whoIsHere()
except AttributeError:
  print("Either no class method called whoIsHere, or calling whoIsHere creates an AttributeError.")
  print("Check your spelling!  Check you added underscores everywhere before usedNames")
  print("Check method requires no input.")
  sys.exit(1)

try:
  AI1 = AI()
  AI2 = AI()
  AI3 = AI()
  AI4 = AI()
except:
  print("Error created when initialising AIs with AI()")
  print("Check your class name and init function.")
  sys.exit(1)

ans = AI.whoIsHere()

names = []
for obj in [AI1, AI2, AI3, AI4]:
  names.append(obj.name)
  if not( obj.name in ans ):
    print("AI name not getting added to output of whoIsHere?")
    sys.exit(1)

if set(ans) != set(names).union( set(org) ):
  print("Output of whoIsHere contains something other than AI names!")
  sys.exit(1)

print("All tests passed")
sys.exit(0)