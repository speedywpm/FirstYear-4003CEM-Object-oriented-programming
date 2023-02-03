#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <sys/stat.h>

SCENARIO( "Code has been compiled" )
{
    const std::string path = "bin/";
    const std::string exec = path + "byhand";
    
    // directory exists
    struct stat info;
    const auto dResult = stat( path.c_str(), &info );

    if( dResult != 0 && !(info.st_mode & S_IFDIR) )
        FAIL( path + " directory does not exist" );

    // exec exists
    const auto fResult = stat( exec.c_str(), &info );

    if( fResult != 0 )
        FAIL( exec + " does not exist" );

    // exec is execable      
    if( access( exec.c_str(), X_OK) != 0 )
        FAIL( exec + " is not an executable file" );

    // check output
    std::unique_ptr<FILE, decltype(&pclose)> pipe( popen( exec.c_str(), "r" ), pclose );
    std::array<char, 128> buffer;
    std::string result;
    if( !pipe ) 
        FAIL( "Test script failed, could not open pipe" );
    else
        while( fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr ) 
            result += buffer.data();
    
    std::string expected = "1+2=3";
    if( result.find( expected ) == std::string::npos )
        FAIL( "Expected \"" + expected +"\" but got \"" + result + "\"" );
}
