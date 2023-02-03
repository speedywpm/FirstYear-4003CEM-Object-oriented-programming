# 4003CEM-inheritance

## lab_animal1
What happens if we add the following line of code to the end of the `main` function in `lab_animal1.cpp`?
```c++
a1.wander();
```

## lab_animal2
Add the following line of code to the end of `lab_animal2.cpp`.
```c++
a1.wander();
```
What happens when we run the code now?

## lab_animal3a
Open `lab_animal3.h` which to start with includes the two class definitions from `lab_animal2.h`.  Underneath, add a third class definition, for a class called `Bird`. All instances of `Bird` should have an attribute `canFly` which is a Boolean and access to a method `flap`.  The `flap` method should print a message containing the word `flying` only if the object in question has attribute `canFly` equal to `true`.

This will mean creating an appropriate `Bird` constructor as well. 
In order to pass the tests make sure that it expects the arguments in the following order name, colour and "can fly".

## lab_animal3b
Add a line of code to the end of your solution in `lab_animal3.cpp` which assigns to a variable `myBird` an object of the `Bird` class which can fly, has name `"Tweety"` and is coloured `"Yellow"`. 

Get `myBird` to wander.

## lab_animal4
Add a `display()` method to `Bird`.
As with `Dog` the behaviour of the method should change depending on the attribute values for the object.
If the `Bird` can fly it should state that it is a `flying` bird.
If the `Bird` cannot fly it should state that is is a `flightless` bird.

## lab_animal5
The `display()` method approach that we have used here is simple but not good approach for real code. We already have a method for printing things in C++, `std::cout`.
If makes a lot of sense for us to get our classes to work properly with `cout` because if we do we automatically get compatibility with several other c\++ features.

Copy your code from `lab_animal4.h` into `lab_animal5.h`.
Replace the `display()` methods with `friend` methods that overload the `<<` operator as discussed in the lecture.

## lab_date and lab_time

Open the files `lab_date.h` and `lab_time.h`.

- `lab_date.h` defines a class `Date`:
-- Every instance has three attributes: `day`, `month`, `year`.  
-- There is a method `forward` which moves the object's date on by one day (updating months and year accordingly).  
-- It uses a class attribute `monthDays` of the number of days in each month.

- `lab_time.h` defines a class `Time`:
-- Every instance has two attributes: `hr` and `min`.  
-- There is a method `tick` which moves the object's time on by one minute (updating hour accordingly).  

Both classes also have simple `constructor` and `display` methods.

Experiment with the classes and try out the methods.

## lab_datetime
Fix the leap year and other rollover bugs in the `DateTime` class.
- You should already have the correct leap year logic from the previous weeks.
- How would you go about testing the 3 parts of the `DateTime` class? (i.e. `Date`, `Time` and `DateTime`).Remember to ask the lab staff any questions you have - don't be shy - we are here to help!

## lab_database
In the file `lab_database.h` write code to implement a basic database of people in a university according to the class Hierarchy Diagram shown in Images/database file.

Of course, in reality there are far more sophisticated tools for making databases - this is just an exercise in class design.

Remember, in each box:
- The top part is the class name.
- The middle part are the attributes (all object attributes here).
- The bottom part are the methods.

The arrows show the inheritance relationships.  So `Staff` should be an extension of `Person` for example.

- Each `constructor` should take a name parameter.  
  - With the exception of the PhdStudent, who should also take a parameter of type `Academic` to use as the `supervisor`.
  - This is a more challenging class so maybe work on that one last.
- `classesTeaching` and `modules` should be initialised as empty vectors.
- `id` should be initalised as a random number.
- `feesPaid` should be initialised as `false`.

All other attributes are initialised as empty strings. The setters should require appropriate parameters.

You can of course extend your code as you wish.