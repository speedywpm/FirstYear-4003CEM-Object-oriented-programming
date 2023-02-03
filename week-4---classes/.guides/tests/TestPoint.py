#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')
from PointArithmetic import Point

pt1 = Point(1,2)
pt2 = Point(2,4)
pt3 = pt1 + pt1

ans1 = pt1==pt2
ans2 = pt2==pt3

if ans1!=False:
  print("Wrong answer from == when different points")
  sys.exit(1)
if ans2!=True:
  print("Wrong answer from == when same points")
  sys.exit(1)

print("Tests passed")
sys.exit(0)