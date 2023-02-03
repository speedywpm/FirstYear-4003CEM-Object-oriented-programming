# tell cmake where to put the executables that it creates
#   also creates the directory if needed
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin ) 

# tell cmake where to find the catch2 library
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/helper/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# tell cmake where to find the captureio library
set(CAPIO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/helper/captureio)
add_library(Capio INTERFACE)
target_include_directories(Capio INTERFACE ${CAPIO_INCLUDE_DIR})

# create the tests
#   test files start with "test_" and end in ".cpp"
#   create a seperate executable for each test file
enable_testing()  
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp")
foreach(filename ${files})
    # if test file is "test_thingy.cpp" then created test will be called "test_thingy"        
    get_filename_component(THIS_TEST ${filename} NAME_WE)
    set(TEST_RUNNER ${THIS_TEST})

    # create the executable, include the catch2 library
    add_executable(${TEST_RUNNER} ${filename} ${HEADERS})
    target_link_libraries(${TEST_RUNNER} Catch)
    target_link_libraries(${TEST_RUNNER} Capio)

    # say that this executable is a test so that ctest will run it
    add_test(NAME ${THIS_TEST}
       COMMAND ${TEST_RUNNER} )
endforeach()

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/test_*.py")
foreach(filename ${files})
    # if test file is "test_thingy.py" then created test will be called "test_thingy"        
    get_filename_component(THIS_TEST ${filename} NAME_WE)
    set(TEST_RUNNER ${THIS_TEST})

    add_test(${THIS_TEST} "python3" ${filename})
endforeach()
