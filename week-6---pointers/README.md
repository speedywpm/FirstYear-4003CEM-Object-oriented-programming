# 4003CEM-pointers

## lab_pointers
- Complete lab\_pointers.cpp.
-- Each of the test functions expects a pointer to a different type of variable, pass each function a pointer to the correct type.
- Run the code.
-- How much space do the different types need?
-- How much space do the different pointers need?

## lab_dynamic
- Compile the lab\_dynamic code.
- Run the code.
-- Does the program produce any errors?
- Compile the lab\_dynamic code again, but THIS time check for memory leaks.
-- You will want to add extra debugging information to your code using the `-g` option.
    `g++ --std=c++14 -g lab_dynamic.cpp -o bin/lab_dynamic`
-- If you are using CMake then you can compile in debug mode using the command below and then calling your normal compile command.
		`cmake . -DCMAKE_BUILD_TYPE=Debug`
- Run your code using a memory leak checker. 
--The default Linux checker is Valgrind.
    `valgrind --leak-check=yes bin/lab_dynamic`
-- What's wrong?
- Fix lab\_dynamic.

## lab_adaptive
- Complete the lab\_adaptive code.
-- The program should ask the user for a size, read in that many numbers and then print those numbers in reverse order.
-- Some C++ code has been provided to get your started as well as a complete Python version.
-- For the purposes of this task you are not allowed to use vectors.
- Test your program for memory leaks.

## lab_smart
- Convert your lab\_adaptive code to use smart\_pointers instead of traditional pointers.
-- Save your new code as lab_smart.cpp.
-- Consider which type of smart pointer is best used in this case.
- Test your program for memory leaks.

## Advanced
- Convert your lab\_adaptive code to use vectors instead of arrays.
-- Save your new code as lab_vector.cpp.
- Test your program for memory leaks.
