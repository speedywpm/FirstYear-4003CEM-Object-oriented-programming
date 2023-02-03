#include <iostream>
using namespace std;

#include "lec_sep_concerns.h"

int main()
{
	JokeStore js;
	js.load( "Lecture/jokes.txt" );

	cout << js.random() << endl;

	return 0;
}