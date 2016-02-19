#include<stdio.h>

int main()
{
  int x, y;
  printf("Podaj liczbe naturalna:\n");
  scanf("%d", &x);
  y=x%3;
  printf("Reszta z dzielenia przez 3: %d\n", y);
  return y;
}
