//Napisać funkcję typu void, która ma
    //dwa całkowite parametry wejściowe n i k, k≠0,
    //dwa całkowite parametry wyjściowe:
        //q równy ilorazowi całkowitemu n przez k, oraz
        //r równy reszcie z dzielenia n przez k.
//Ta funkcja nie może mieć żadnych innych parametrów, nie może odwoływać się do zmiennych globalnych i oczywiście nie może niczego czytać ani pisać -- jej jedyna komunikacja z resztą programu odbywa się przez parametry.
//Napisać program, który wczytuje dwie liczby całkowite i wywołuje powyższą funkcję, a następnie drukuje iloraz całkowity oraz resztę z dzielenia wczytanych liczb.

#include<stdio.h>

void funkcja(int n, int k, int *q, int *r)
{
  *q=(n/k);
  *r=(n%k);
}

int main()
{
  int iloraz, reszta, l1, l2;
  scanf("%d %d", &l1, &l2);
  funkcja(l1, l2, &iloraz, &reszta);
  printf("Iloraz: %d\nReszta: %d\n", iloraz, reszta);
}
