//Napisać program w C, który wczytuje liczbę naturalną i przekazuje systemowi operacyjnemu (przez return w main-ie) resztę z dzielenia tej liczby przez 3;
//skrypt bashowy, który uruchamia powyższy program, przechwytuje wartość przekazaną systemowi i drukuje ją.


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
