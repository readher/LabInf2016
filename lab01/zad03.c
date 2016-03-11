//Napisać programy testujące działanie operatorów z efektami ubocznymi w różnych sytuacjach, od których może zależeć wynik działania.

#include <stdio.h>

void wypisz_tab(int tab[], int size)
{
  int i;
  for(i=0;i<size;)
    printf("%d ", tab[i++]);
  printf("\n");
}

void fun1(int tab[], int a)
{
  int i,tmp;
  tmp=a;
  tab[a++]=0;
  a=tmp;
  tab[++a]=1;
  printf("\nTest 1:\n");
  printf("tab[a++]=0, tab[++a]=1:\n");
  for(i=0;i<5;++i)
    printf("%d ", i);
  printf("\n");
  wypisz_tab(tab, 5);
  printf("To nie to samo!\n");
}

void fun2(int x)
{
  int y,z;
  printf("\nTest 2 i test 3:\n");
  y=(x+=2);
  z=(x%=3)+(x%=4);
  printf("x=%d, y=%d, z=%d\n", x, y, z);
}

int main()
{
  int tab[5] = {1,2,3,4,5};
  printf("Tabela:\n");
  wypisz_tab(tab, 5);
  fun1(tab, 3);
  fun2(5);
  
  return 0;
}
