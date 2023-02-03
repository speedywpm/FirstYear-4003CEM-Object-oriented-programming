#include <iostream>
using namespace std;

class Thingy
{
private:
    double* pointer;

public:
    /** constructor **/
    Thingy( double value )
    {
        pointer = new double;
        *pointer = value;
    }

    /** destructor **/
    ~Thingy()
    {
        delete pointer;
    }

    /** getter **/
    double get_value() const
    {
        return *pointer;
    }
};

int main()
{
    Thingy thing( 123.456 );  

    std::cout << thing.get_value() << std::endl;
    
    return 0;
}
