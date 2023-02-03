#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "changeable";
	const string c = "unchangeable";

	cout << s << " " << c << endl;

	s = "changed";
	c = "syntax error"; // will fail to compile

	cout << s << " " << c << endl;

	return 0;
}