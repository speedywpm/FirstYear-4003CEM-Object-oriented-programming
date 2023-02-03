#!/usr/bin/python3
import sys
sys.path.insert(0, '/home/codio/workspace')

from PersonDatabase import Person, Staff, Academic, Student, PhDStudent

# Instantiation Checks
try:
  myPerson = Person("Bob")
except:
  print("Exception triggered creating Person object via:")
  print("Person('Bob')")
  sys.exit(1)
try:
  myStaff = Staff("Bob")
except:
  print("Exception triggered creating Student object via:")
  print("Staff('Bob')")
  sys.exit(1)
try:
  myAcademic = Academic("Bob")
except:
  print("Exception triggered creating Academic object via:")
  print("Academic('Bob')")
  sys.exit(1)    
try:
  myStudent = Student("Bob")
except:
  print("Exception triggered creating Student object via:")
  print("Student('Bob')")
  sys.exit(1)  
try:
  myPhDStudent = PhDStudent("Bob")
except:
  print("Exception triggered creating PhDStudent object via:")
  print("PhDStudent('Bob')")
  sys.exit(1)    

## Inheritance Checks  
if isinstance(myStaff, Person)!=True:
  print("Your code suggests Staff are not People?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
if isinstance(myStaff, Student)!=False:
  print("Your code suggests Staff are Students?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
if isinstance(myStudent, Person)!=True:
  print("Your code suggests Students are not People?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
if isinstance(myStudent, Staff)!=False:
  print("Your code suggests Students are Staff?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
if isinstance(myPhDStudent, Student)!=True:
  print("Your code suggests PhD Students are not Students?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
if isinstance(myAcademic, Staff)!=True:
  print("Your code suggests Academics are not Staff?")
  print("Check class header is requesting inheritance")
  sys.exit(1)
  
# Attribute Checks
try:
    if myPerson.name!="Bob":
        print("Wrong name in name attribute?")
        sys.exit(1)
except AttributeError:
    print("Could not access name attribute?")
    print("It should not be private")
    sys.exit(1)
try:
    if myPerson.address!=None:
        print("Address not initialised to None")
        sys.exit(1)
except AttributeError:
    print("Could not access address attribute?")
    print("It should not be private")
    sys.exit(1)
try:
    myPerson.setAddress("Cov")
except AttributeError:
    print("Could not run method setAddress.")
    print("Check def has two parameters: for object and address string")
    sys.exit(1)
if myPerson.address!="Cov":
    print("Address not updated correcty")
    sys.exit(1)
try:
    myPerson.getID()
except:
    print("Could not run getID method?")
    print("Check def only has one parameter, self.")
    sys.exit(1)

for pair in [("myStaff", "address", "setAddress"), 
             ("myStaff", "jobTitle", "setJobTitle"), 
             ("myStudent", "course", "setCourse"),
             ("myPhDStudent", "supervisor", "setSupervisor"),
             ("myPhDStudent", "dissertationTitle", "setTitle")]:
    strO = pair[0]
    strA = pair[1]
    strM = pair[2]
    try:
        if eval(strO+"."+strA)!=None:
            print(strA + " not initialised to None")
            sys.exit(1)
    except AttributeError:
        print("Could not access " + strA + " attribute?")
        print("It should not be private")
        sys.exit(1)
    try:
        eval(strO+"."+strM+"('StringyMcString')")
    except AttributeError:
        print("Could not run method "+ strM)
        print("Check def has two parameters: for object and string string")
        sys.exit(1)
    if eval(strO+"."+strA)!="StringyMcString":
        print(strA + " not updated correcty")
        sys.exit(1)
    
try:
    f = myStudent.feesPaid
except:
    print("Could not access feesPaid attribute?")
    print("It should not be private.")
    sys.exit(1)
if f!=0:
    print("feesPaid not initialised to zero?")
    sys.exit(1)
try:
    myStudent.payFees(100)
except:
    print("Could not run payFees method.")
    print("Method should have two inputs: self and number")
    sys.exit(1)
f = myStudent.feesPaid
if f!=100:
    print("feesPaid not updated correctly following payFees call!")
    sys.exit(1)

try:
    if myStudent.modules!=[]:
        print("modules not initialised to empty list")
        sys.exit(1)
except AttributeError:
    print("Could not access modules attribute of Student")
    print("Should not be private")
    sys.exit(1)
try:
    myStudent.assignModule("121COM")
except:
    print("error running assignModule")
    print("Method should have two inputs: self and str for one module")
    sys.exit(1)
if not("121COM" in myStudent.modules):
    print("modules list not updated correctly by assignModule")
    sys.exit(1)

try:
    if myAcademic.classesTeaching!=[]:
        print("classesTeaching not initialised to empty list")
        sys.exit(1)
except AttributeError:
    print("Could not access classesTeaching attribute of Academic")
    print("Should not be private")
    sys.exit(1)
try:
    myAcademic.assignTeaching("121COM")
except:
    print("error running assignTeaching")
    print("Method should have two inputs: self and str for one module")
    sys.exit(1)
if not("121COM" in myAcademic.classesTeaching):
    print("classesTeaching list not updated correctly by assignTeaching")
    sys.exit(1)    
    
print("Tests all passed")
sys.exit(0)
