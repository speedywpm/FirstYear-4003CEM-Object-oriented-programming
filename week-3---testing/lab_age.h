/* Use the unit tests provided in test_age.cpp to figure out 
    the full requirements for this function and then modify 
    this function so that it passes all of the tests */

#include <string>

/**
 * Return a string containing an age descriptor for a supplied age
 * 
 * @param age the age of a person
 * @return an age descriptor
 */
std::string age_description( int age )
{
  if (age>=0 && age <=122)
  {
    if (age<5)
    {return "baby";}
    else if(age>=5 && age<13)
    {return "child";}
    else if(age>13 && age <=19)
    {return "teenager";}
    else if(age>19 && age<65)
    {return "adult";}
    else if(age>65)
    {return "oap";}
  }
  else{
    return "lying";
  }

}
