#!/usr/bin/python3
import sys
from io import StringIO
sys.path.insert(0, '/home/codio/workspace')

from Animal3 import *

try:
  if type(myBird)!=Bird:
    print("variable 'myBird' is not an object of class Bird!")
    sys.exit(1)
except NameError:
  print("variable 'myBird' does not exist!")
  sys.exit(1)

if myBird.name!="Tweety":
  print("Attribute name of object myBird is not 'Tweety'")
  sys.exit(1)
if myBird.colour!="Yellow":
  print("Attribute colour of object myBird is not 'Yellow'")
  sys.exit(1)
if myBird.canFly!=True:
  print("Attribute canFly of object myBird is not True")
  sys.exit(1)
  
print("Tests all passed")
sys.exit(0)