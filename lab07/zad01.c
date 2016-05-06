//Napisać program   od_konca.c , którego wywołanie z argumentami spowoduje wypisanie tych argumentów w odwrotnej kolejności. Np. wywołanie
 //./od_konca  Ty. gdzie tam, zawsze tam, Byc
//wydrukuje tekst
 //Byc tam, zawsze tam, gdzie Ty.

#include <stdio.h>

int main (int ile_arg, char* arg[ ])
{
    int i;
    for(i=ile_arg-1; i>0; i--)
    {
        printf("%s ", arg[i]);
    }
    printf("\n");
}
