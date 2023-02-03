import random

class AI:
  """A class for AI characters in a game."""
  
  f = open("FirstNames.txt")
  nameList = f.read().split("\n")
  f.close()
  print("List of " + str(len(nameList)) + " names generated.")
  
  def __init__(self):
    self.name = random.choice(AI.nameList)
    self.level = 1
    print("AI " + self.name + " created.")

  def sayHello(self):
    message = self.name + ": "
    message = message + "Hello! My name is " + self.name
    message = message + " I am level " + str(self.level)
    print(message)
    
print("") 
firstAI = AI()
secondAI = AI()   
print("")
firstAI.sayHello()