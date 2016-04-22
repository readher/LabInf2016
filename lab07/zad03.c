//W programie z zadania 2 wymieni/c funkcję   sortowanie   na możliwie szybko działającą (np. bubble-sort na merge-sort).
//Dla oceny szybkości działania programu można zaraz przed rozpoczęciem sortowania umieścić komendę
  //clock_t  pocz = clock();
//a po jego zakończeniu komendę
  //clock_t  koniec = clock();
  //printf(" Czas wykonania: %lf sek.\n\n",
         //(double)(koniec-pocz) / CLOCKS_PER_SEC
        //);
//Żeby to działało, na początku programu należy umieścić odwołanie do pliku nagłówkowego   #include<time.h> .

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_DL_IM 11
#define MAX_DL_NA 17
#define DUZO 10000

typedef struct osoba
{
  char imie[MAX_DL_IM];
  char nazwisko[MAX_DL_NA];
  int pensja;
} osoba;

osoba tabl[DUZO];

int czytanie(char plik1[])
{
        int linie = 0;
  FILE* plik;
        plik = fopen(plik1, "r");
        int w;
        do
        {
                fscanf(plik, "%s", tabl[linie].imie);
                fscanf(plik, "%s", tabl[linie].nazwisko);
        w =     fscanf(plik, "%i", &tabl[linie].pensja);
        linie++;
        }while(w  != EOF);
        fclose(plik);
        return linie-1;
}

void pisanie(char plik1[], int ile)
{
        FILE* plik;
        plik = fopen(plik1, "w");
        int i;
        for(i=0;i<ile;i++)
        {
          fprintf(plik, "%s \t", tabl[i].imie);
          fprintf(plik, "%s \t", tabl[i].nazwisko);
          fprintf(plik, "%i \n", tabl[i].pensja);
        }
}
int poprzedza (osoba os1, osoba os2)
{
  if (strcmp(os1.nazwisko, os2.nazwisko) < 0) return 1;
  else if (strcmp(os1.nazwisko, os2.nazwisko) > 0 ) return 0;
  else return (strcmp(os1.imie, os2.imie) < 0);
}
void sortowanie ( int ile, osoba tabl[])
{
    clock_t  pocz = clock();
    int i, j;
    for (i = ile; i > 1; i--)
    for (j = 1; j < i-1; j++)
      if(poprzedza(tabl[j], tabl[j-1]))
      {
        osoba pom = tabl[j];
        tabl[j] = tabl[j-1];
        tabl[j-1] = pom;
      }
    clock_t  koniec = clock();
    printf(" Czas wykonania: %lf sek.\n\n", (double)(koniec-pocz) / CLOCKS_PER_SEC);
}

int main (int arg_num, char* arg[])
{
        if(arg_num == 3)
        {
          int ile = czytanie(arg[1]);
          if(ile > 0){
            sortowanie(ile, tabl);
            pisanie(arg[2],ile);
        }
}
        else
        {
            printf(" blad \n");
        }
}
