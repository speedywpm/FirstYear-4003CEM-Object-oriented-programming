#define CATCH_CONFIG_MAIN
#include "catch.hpp"


SCENARIO( "CMakeFile has been updated" )
{
    // open file
    const std::string filename = "CMakeLists.txt";
    std::ifstream file( filename );
    
    if( !file.is_open() )
        FAIL( "Could not open " + filename );

    // declare regexes
    std::vector< std::tuple<std::regex,std::string,size_t> > regexes 
        { { std::regex( "^[^#]*add_executable\\s*\\(\\s*validate\\s.*validate.cpp.*\\)" ), "add_executable", 0 }, 
          { std::regex( "^[^#]*add_library\\s*\\(\\s*[\\w]{1,}\\s{1,}.*passwords.cpp.*\\)" ), "add_library", 0 },
          { std::regex( "^[^#]*target_link_libraries\\s*\\(\\s*validate\\s.*\\)" ), "target_link_libraries", 0 } };
    std::smatch match;

    // process file
    std::string line;
    while( std::getline( file, line ) )
        for( auto &re : regexes )
        {
            if( std::regex_match( line, match, std::get<0>(re) ) )
                std::get<2>(re)++;
        }

    // check all regexes matched
    for( auto &re : regexes )
        if( !std::get<2>(re) )
            FAIL( "Could not find expected \"" + std::get<1>(re) + "\" statement" );
}

