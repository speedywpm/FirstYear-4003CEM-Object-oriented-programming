#include <math.h>

float my_sqrt( float x )
{
  bool abc= false;
    float y=(x+1)/2;
  if (x>0)
  {
    while(abc==false)
    {
      
      
        if (-0.001 < (y*y)-x && (y*y)-x < 0.001)
        {
          return y;
          abc=true;
        }
      else
      {
        y=(y+x/y)/2;
        abc=false;
      }
    }
  } 
}