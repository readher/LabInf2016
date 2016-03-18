//Sprawdzić, wykonując odpowiednie testy, jak działają operacje rzutowania z typów ,,mniejszych'' do ,,większych'' i odwrotnie.

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
	printf("FLT_MAX dla int: %i\n", FLT_MAX);
	printf("DBL_MAX dla int: %i\n", DBL_MAX);
	printf("LDBL_MAX dla double: %lf", LDBL_MAX);
}
