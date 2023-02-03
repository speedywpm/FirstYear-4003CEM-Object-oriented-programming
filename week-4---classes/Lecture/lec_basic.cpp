#include <iostream>
using namespace std;

class MyClass
{
public:
    int someVariable;

    void some_function()
    {
        // do something
    }
};

int main()
{
    // creating an instance of the class
    MyClass anInstance;

    // using an attribute from the instance
    anInstance.someVariable = 42;
    
    // using a function from the instance
    anInstance.some_function();

    return 0;
}