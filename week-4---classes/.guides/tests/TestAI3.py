import sys

f1 = open("AI3.py")
f2 = open(".guides/tests/orgAI3.py")
contents1 = f1.read()
contents2 = f2.read()
f1.close()
f2.close()

lines1 = contents1.split("\n")
lines2 = contents2.split("\n")

if len(lines1)>27:
  print("You added more than one new line!")
  sys.exit(1)
elif len(lines1)<26:
  print("You deleted lines of code?")
  sys.exit(1)
elif len(lines1)==26:
  print("You did not add a line?")
  sys.exit(1)

for i in range(26):
  if lines1[i] != lines2[i]:
    print("Line " + str(i+1) + " has been edited")
    sys.exit(1)

student = lines1[26].rstrip()
ans = "secondAI.sayHello()"
if student!=ans:
  print("Line 27 not as expected.")
  print("Expected: " + ans )
  print("Recieved: " + student)
  sys.exit(1)

print("All tests passed")
sys.exit(0)