# tell cmake where to put the executables that it creates
#   also creates the directory if needed
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin ) 

# compile the lecture examples
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/lec_*.cpp")
foreach(filename ${files})
    # if lec file is "lec_thingy.cpp" then created test will be called "bin/lec_thingy"        
    get_filename_component(EXEC ${filename} NAME_WE)

    # skip over the lec_error example as it won't compile
    if(EXEC STREQUAL "lec_error")
        continue()
    endif()

    # create the executable
    add_executable(${EXEC} ${filename} ${HEADERS})
endforeach()

