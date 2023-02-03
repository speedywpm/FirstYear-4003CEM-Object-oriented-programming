#ifndef RANDOMNAME_H
#define RANDOMNAME_H

#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <exception>
#include <iostream>

class RandomValues
{
private:
    std::vector<std::string> names;

public:
    void load_names( const char* filename="names.txt" )
    {
        // open the names file
        std::ifstream file;
        file.open( filename );

        // read the names file
        std::string buffer;
        while( getline( file, buffer ) )
            names.emplace_back( std::move(buffer) );
    }
    
    RandomValues() { load_names(); }

    /** select a random name from the values loaded into memory **/
    std::string name() const
    {   
        if( names.empty() ) throw std::runtime_error( "No names loaded" );
    
        std::random_device generator;
        std::uniform_int_distribution<size_t> distribution( 0, names.size()-1 );

        return *next( begin(names), distribution(generator) );
    }

    /** generate a random damage amount 
     *  damage is affected by supplied level, higher levels will produce higher
     *  damages on average **/
    int damage( int level ) const
    {
        std::random_device generator;
        std::uniform_int_distribution<int> distribution( level*1000, 20000 );
        return distribution( generator );
    }
};

#endif
