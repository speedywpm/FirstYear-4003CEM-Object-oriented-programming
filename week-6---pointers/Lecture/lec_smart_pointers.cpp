#include <iostream>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> pointerA = make_shared<int>();			
	*pointerA = 42;

	cout << pointerA.use_count() << endl; // 1

	shared_ptr<int> pointerB = pointerA;
	cout << pointerA.use_count() << endl; // 2

	pointerB = nullptr;
	cout << pointerA.use_count() << endl; // 1
	
	return 0;
}