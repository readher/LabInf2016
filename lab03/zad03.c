//Sprawdzić, wykonując odpowiednie testy, jak działają operacje rzutowania z typów ,,mniejszych'' do ,,większych'' i odwrotnie.

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
	printf("FLT_MAX dla int: %i\n", FLT_MAX);
	printf("DBL_MAX dla int: %i\n", DBL_MAX);
	printf("LDBL_MAX dla double: %lf", LDBL_MAX);
 	printf("FLT_MAX na (int)FLT_MAX: '%e' do '%i' \n", FLT_MAX, (int)FLT_MAX);
 	printf("DBM_MAX na (int)DBL_MAX: '%e' do '%i' \n", DBL_MAX, (int)DBL_MAX);
 	printf("LDBL_MAX na (double)LDBL_MAX: '%Le' do '%e' \n", LDBL_MAX, (double)LDBL_MAX);
  	printf("INT_MAX na (float)FLT_MAX: '%i' do '%e' \n", INT_MAX, (float)INT_MAX);
  	printf("LLONG_MAX na (double)LLONG_MAX: '%lli' do '%e' \n", LLONG_MAX, (double)LLONG_MAX);
}
