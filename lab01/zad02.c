#include<stdio.h>

int main()
{
  char x;
  while((x=getchar()) != EOF);
  printf("%c", x);
}
