//Tutaj jest niepełny program w C, zawierający prototypy funkcji obsługujących podstawowe działania na listach. Należy dopisać ciała tych funkcji tak, żeby
//    te funkcje działały zgodnie z podanymi komentarzami,
//    prawidłowo działała funkcja odwroc odwracająca listę,
//    program główny drukował ciąg 3 słów:
//      ghi
//      def
//      abc
//Ani w definicji typu lista, ani w ciele funkcji odwroc, ani w części main programu
//niczego nie zmieniać -- tylko wypełnić ciała tych funkcji,których jedyną zawartością jest komentarz.
//Definiowane funkcje (z wyjątkiem funkcji druk) nie mogą niczego pisać ani czytać.
//wbzyl.inf.ug.edu.pl/rails2/jp/list_adt/14
//wbzyl.inf.ug.edu.pl/c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DL_SLOWA 30
typedef struct sl
{
  char slowo[MAX_DL_SLOWA];
  struct sl* dalej;
}* lista;
//=======================================================
int pusta(lista lis)
{
  // jesli  lis  jest lista pusta (wskaznik  NULL)
  // to wartoscia jest liczba rozna od 0, w przeciwnym razie 0
  if(lis==NULL) return 1;
  else return 0;
}
//=======================================================
char* pierwsze(lista lis)
{
  // zwraca pierwsze slowo z listy  lis
  // jesli jest pusta, to dzialanie nieokreslone
  return lis->slowo;
}
//=======================================================
lista reszta(lista lis)
{
  // zwraca liste  lis  z usunietym pierwszym slowem
  // jesli jest pusta, to dzialanie nieokreslone
  return lis->dalej;
}
//=======================================================
lista dolacz(char slow[MAX_DL_SLOWA], lista lis)
{
  // dolacza  slowo  do poczatku listy  lis
  lista pom = (lista)(malloc(sizeof(struct sl)));
  strcpy(pom->slowo, slow);
  pom->dalej=lis;
  return pom;
}
//=======================================================
void druk(lista lis)
{
  // drukuje po kolei wszystkie slowa z  lis
  lista wynik = lis;
  while(wynik!=NULL)
  {
    printf("%s ", wynik->slowo);
    wynik=wynik->dalej;
  }
}
//=======================================================
lista odwroc(lista lis)
{
  // odwraca liste  lis  od konca
  lista pom=NULL;
  char slowo[MAX_DL_SLOWA];
  while(!pusta(lis))
  {
    strcpy(slowo, pierwsze(lis));
    lis=reszta(lis);
    pom=dolacz(slowo, pom);
  }
  return pom;
}
//=======================================================
int main()
{
  lista lis=NULL;
  lis=dolacz("abc", dolacz("def", dolacz("ghi", lis)));
  druk(odwroc(lis));
  return 0;
}
