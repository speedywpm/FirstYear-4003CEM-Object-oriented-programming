#include <stdexcept>

/** Class to store rectangles.  
  Every rectangle has two numbers which define the side lengths.
  We provide methods to calculate various properties. **/
class Rectangle
{
private:
    float side1, side2;

public:
    Rectangle( float x, float y )
    {
        if( x<=0 || y<=0  )
            throw std::range_error( "Sides must be positive values" );

        side1 = x;
        side2 = y;
    }
    float get_side_1() const{
    return side1;
    }
    float get_side_2() const{
    return side2;
    }
    float area() const
    {
        return side1 * side2;
    }
    
    float perimeter() const
    {
        return 2*side1 + 2*side2;
    }

    void scale( float scaleFactor )
    {
        if( scaleFactor <= 0 )
            throw std::range_error( "Scale Factor must be positive" );

        side1 = side1 * scaleFactor;
        side2 = side2 * scaleFactor;
    }
};
