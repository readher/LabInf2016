//W każdym typie liczbowym znaleźć możliwie małe dane, na których wynik jakiegoś działania matematycznego jest już niepoprawny.

#include <stdio.h>

int main()
{
  short s=32767;
  short se=s+10;
  printf("Short: %i + 10 = %i\n", s, se);

  int i=2147483647;
  int ie=i+10;
  printf("Int: %i + 10 = %i\n", i, ie);

  long l=9223372036854775807;
  long le=l+10;
  printf("Long: %li + 10 = %li\n", l, le);

  long ll=9223372036854775807;
  long lle = ll+10;
  printf("Long long: %li + 10 = %li\n", ll, lle);

  float fl=0.000001;
  float fle=fl/2.0;
  printf("Float: %f / 2 = %f\n", fl, fle);

  double d=0.000001;
  double de=d/2.0;
  printf("Double: %f / 2 = %f\n", d, de);

  long double ld=0.000001;
  long double lde=ld/2.0;
  printf("Long double: %Lf / 2 = %Lf\n", ld, lde);
}
