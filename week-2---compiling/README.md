# 4003CEM-compiling

## Compiling by hand
Compile the main.cpp file into an executable called “byhand” using the 3 separate compile commands needed.
This executable should be placed in the bin/ directory.

## Compiling with cmake
Compile the main.cpp file into an executable using the supplied cmake project file.
The project file has been set up to produce and executable called "main".
This should be all the information needed to compile it.

## Editing cmake
The files passwords.h, passwords.cpp and validate.cpp have been provided for you.
passwords.h and passwords.cpp contain a pair of functions, validate.cpp contains a main() that uses those functions.
Edit your CMakeLists.txt file to compile validate.cpp into an executable program called validate.
passwords.h/.cpp should be treated as a library that is used by validate.cpp.