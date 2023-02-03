cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(cppintro CXX)

# turns out that g++ will allow variable length arrays but I 
# dont' want students getting dependant on non-standard features
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

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/lab_*.cpp")
foreach(filename ${files})
    get_filename_component(EXEC ${filename} NAME_WE)
    add_executable(${EXEC} ${filename} ${HEADERS})
endforeach()
