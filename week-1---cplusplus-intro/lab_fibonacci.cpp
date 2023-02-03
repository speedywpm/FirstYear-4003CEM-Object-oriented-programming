#include <iostream>

void fibonacci()
{
  //int a=0;
  //int b=1;
  //int c=0;
  for(int i=0; i<20; i++)
  {
    int p[98]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};
    std::cout << p[i] << std::endl;
    //a=a+b;
    //b=a+b;
  }
}

int main()
{
    fibonacci();

    return 0;
}

