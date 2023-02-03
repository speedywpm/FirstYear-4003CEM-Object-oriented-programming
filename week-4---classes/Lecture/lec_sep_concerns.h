#ifndef LEC_SEP_CONCERNS_H
#define LEC_SEP_CONCERNS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <thread>
#include <chrono>

class Joke
{
private:
	std::vector<std::string> text;

public:
	/** Constructors **/
	Joke();
	Joke( std::vector<std::string> & );
	Joke( std::vector<std::string> && );

	/** Appends a new line to the end of the joke
	 *  Takes a single string parameter **/
	void append( std::string & );

	/** Returns the number of lines in the joke **/
	size_t length() const;

	friend std::ostream& operator<<( std::ostream&, const Joke& );
};

class JokeStore
{
public:
	std::vector< Joke > jokes;
	
public:
	/** Read in a file containing jokes
	 *  Takes a single string parameter, the file path/name to be read
	 *  File should contain jokes separated by a blank line to indicate the 
	 *  end of each joke **/
	bool load( const std::string & );

	/** Pick a joke from the store at random */
	const Joke& random() const;
};

Joke::Joke() {}
Joke::Joke( std::vector<std::string> &_text ) : text(_text) {}
Joke::Joke( std::vector<std::string> &&_text ) : text( std::move(_text) ) {}

void Joke::append( std::string &line ) 
{ 
	text.emplace_back(line); 
}

size_t Joke::length() const 
{ 
	return text.size(); 
}

const Joke& JokeStore::random() const
{
	std::random_device rd;    
	std::mt19937 mt( rd() );
	std::uniform_int_distribution<size_t> random_int(0, jokes.size()-1);

	return *std::next( jokes.begin(), random_int(mt) );
}

bool JokeStore::load( const std::string &filename )
{
	std::ifstream file( filename );
	if( !file.good() ) return false;

	jokes.emplace_back();
	while( file.good() )
	{
		std::string line;
		std::getline( file, line );

		if( line == "" )
			jokes.emplace_back();
		else
			jokes.back().append(line);
	}

	file.close();

	// remove blank jokes
	auto filter = [](Joke &j){ return j.length() == 0; };
	auto newend = std::remove_if( jokes.begin(), jokes.end(), filter );
	jokes.erase( newend, jokes.end() );

	return true;
}

std::ostream& operator<<( std::ostream& os, const Joke& j )
{
	for( auto it=j.text.begin(); it!=j.text.end(); std::advance(it,1) )
	{
		os << *it;
		if( it!=prev(j.text.end()) ) 
			os << std::endl;
		else
			std::this_thread::sleep_for( std::chrono::seconds(2) );
	}

	return os;
}

#endif