#include <stdio.h>

int main() {
  int x;
  printf("Podaj liczbe: \n");
  scanf("%d",&x);
  int day = (x & 0x0000001F);
  int month = (x & 0x000001E0) >> 5;
  int year = (x & 0xFFFFFE00) >> 9;
  printf("Dzien = %d, Miesiac = %d, Rok = %d\n",day,month,year);
  return 0;
}
