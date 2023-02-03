cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(cppintro CXX)

# turns out that g++ will allow variable length arrays but I 
# don't want students getting dependant on non-standard features
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvla -Werror=vla")

# limit number of errors shown to 1
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors")

# config directories
include_directories(${CMAKE_SOURCE_DIR})

# add tests
enable_testing() 
add_subdirectory(Testing)
add_subdirectory(Lecture)

# tell cmake where to put the executables that it creates
#   also creates the directory if needed
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin ) 

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_executable( leap lab_leap.cpp )

add_executable( welcome lab_welcome.cpp )

add_executable( age lab_age.cpp )

add_executable( reverse lab_reverse.cpp )

add_executable( fibonacci lab_fibonacci.cpp )

add_executable( even lab_even.cpp )

add_executable( sqrt lab_sqrt.cpp )

add_executable( recursion lab_recursion.cpp )

add_executable( hello EXCLUDE_FROM_ALL lab_hello.cpp )

