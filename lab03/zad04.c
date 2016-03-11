#include <stdio.h>

int main()
{
  int i=1;
  printf("FLOAT:\n");
  float x=1.0;
  while(1.0+x>1.0)
  {
    x=x/2.0;
    i++;
  }
  printf("%i dzielen, %f -> %e\n\n", i, x, x);

  i=1;
  printf("DOUBLE:\n");
  double y=1.0;
  while(1.0+y>1.0)
  {
    y=y/2.0;
    i++;
  }
  printf("%i dzielen, %f -> %e\n\n", i, y, y);

  i=1;
  printf("LONG DOUBLE:\n");
  long double z=1.0;
  while(1.0+z>1.0)
  {
    z=z/2.0;
    i++;
  }
  printf("%i dzielen, %Lf -> %Le\n\n", i, z, z);
  
  return 0;
}