//Napisać ,,czysty'' program, czyli bez efektów ubocznych, działający tak samo jak powyższa pętla for. 

#include<stdio.h>

int main()
{
  char x;
  while((x=getchar()) != EOF);
  printf("%c", x);
}
