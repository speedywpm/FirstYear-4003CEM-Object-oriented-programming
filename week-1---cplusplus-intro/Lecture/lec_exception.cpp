#include <iostream>
#include <stdexcept>
#include <random>
using namespace std;

int main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> random_int(0,3);

	try
	{
		const int randomValue = random_int(mt);
		cout << randomValue << endl;

		if( randomValue == 0 )
			throw logic_error( "Logic" );
		else if( randomValue == 1 )
			throw 42;
		else if( randomValue == 2 )
			throw exception();
		
		cout << "Everything is fine" << endl;
	}
	catch( logic_error& e ) {
		cerr << "Oh no! a logic error - " << e.what() << endl; }
	catch( int e ) {
		cerr << "Oh no! error " << e << endl; }
	catch(...) {
		cerr << "Oh no! an unknown error" << endl; }
	
	return 0;
}