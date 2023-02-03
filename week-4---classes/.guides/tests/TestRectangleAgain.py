#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from Rectangle import Rectangle

r = Rectangle(4,7)

try:
  s = r.__str__()
except AttributeError:
  print("No method called __str__?")
  # Should never happen as would inherit one
  sys.exit(1)

if s!="(4, 7)" and s!="(4,7)":
  print("Output of __str__ is wrong!")
  print("Expected: '(4,7)'")
  print("Recieved: '" + s + "'")
  sys.exit(1)

print("Tests passed")
sys.exit(0)