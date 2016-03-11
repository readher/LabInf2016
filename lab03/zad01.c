//Napisać program, który bada poznane typy liczbowe w C

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
  printf("short:\nDolna wartosc: %i\nGorna wartosc: %i\nZiarno: -\nPrecyzja: -\n\n", SHRT_MIN, SHRT_MAX);
  printf("int:\nDolna wartosc: %i\nGorna wartosc: %i\nZiarno: -\nPrecyzja: -\n\n", INT_MIN, INT_MAX);
  printf("long:\nDolna wartosc: %li\nGorna wartosc: %li\nZiarno: -\nPrecyzja: -\n\n", LONG_MIN, LONG_MAX);
  printf("long long:\nDolna wartosc: %lli\nGorna wartosc: %lli\nZiarno: -\nPrecyzja: -\n\n", LLONG_MIN, LLONG_MAX);
  printf("float:\nDolna wartosc: %f\nGorna wartosc: %f\nZiarno: %f\nPrecyzja: %i\n\n", FLT_MIN, FLT_MAX, FLT_EPSILON, FLT_DIG);
  printf("double:\nDolna wartosc: %lf\nGorna wartosc: %lf\nZiarno: %lf\nPrecyzja: %i\n\n", DBL_MIN, DBL_MAX, DBL_EPSILON, DBL_DIG);
  printf("long double:\nDolna wartosc: %Lf\nGorna wartosc: %Lf\nZiarno: %Lf\nPrecyzja: %i\n\n", LDBL_MIN, LDBL_MAX, LDBL_EPSILON, LDBL_DIG);
}
