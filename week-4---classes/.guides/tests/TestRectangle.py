#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from Rectangle import Rectangle

r = Rectangle(55,77)

try:
  s1 = r.getSide1()
except AttributeError:
  print("No method called getSide1?")
  print("Check spelling!")
  sys.exit(1)
try:
  s2 = r.getSide2()
except AttributeError:
  print("No method called getSide2?")
  print("Check spelling!")
  sys.exit(1)

if s1!=55 or s2!=77:
  print("Output of getters is wrong!")
  sys.exit(1)

print("Tests passed")
sys.exit(0)