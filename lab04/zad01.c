//Opracować zestaw operacji na liczbach zespolonych potrzebny do prawidłowego działania tego programu.
//W tym celu należy prototypy (nagłówki) podanych tam funkcji, realizujących działania, zastąpić lub uzupełnić pełnymi definicjami działań.
//Oczywiście dla napisania tych funkcji, potrzebne jest zastosowanie własnej wiedzy o liczbach zespolonych (np. z algebry).

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <complex.h>

typedef struct
{
  double rea, ima;
} zespol;

void err(char s[])
{
  printf("\n!!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}

zespol zesp_zestawic(double r, double i)
{
  zespol z;
  z.rea=r;
  z.ima=i;
  return z;
}

zespol zesp_get(void)
{
  char ch;
  zespol z;
  int znak_im;
  do
  {
    ch=getchar();
  } while(isspace(ch));
  if(ch=='(')
  {
    if(scanf("%lf", &(z.rea))==1)
    {
      do
      {
        ch = getchar();
      } while(isspace(ch));
      if(ch=='+' || ch=='-')
      {
        if(ch=='+') znak_im=1;
        else znak_im=-1;
        if(scanf("%lf", &(z.ima))==1)
        {
          do
          {
            ch=getchar();
          } while(isspace(ch));
          if(ch=='i')
          {
            do
            {
              ch=getchar();
            } while(isspace(ch));
            if(ch==')')
            {
              if(znak_im==-1) z.ima=-z.ima;
            } else err("brak koncowego nawiasu");
          } else err("brak 'i' na koncu czesci urojonej");
        } else err("niepoprawna czesc urojona");
      } else err("po czesci rzeczywistej brak znaku '+' lub '-'");
    } else err("niepoprawna czesc rzeczywista");
  } else err("brak rozpoczynajacego nawiasu");
  return z;
}

void zesp_print(zespol z)
{
  if(z.ima>=0) printf("(%.2lf+%.2lfi)", z.rea, z.ima);
  else printf("(%.2lf-%.2lfi)", z.rea, -z.ima);
}

zespol zesp_dodac(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea+z2.rea;
  wyn.ima=z1.ima+z2.ima;
  return wyn;
}

zespol zesp_odjac(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea-z2.rea;
  wyn.ima=z2.ima-z2.ima;
  return wyn;
}

zespol zesp_razy(zespol z1, zespol z2)
{
  zespol wyn;
  wyn.rea=z1.rea*z2.rea-z1.ima*z2.ima;
  wyn.ima=z1.rea*z2.ima+z1.ima*z2.rea;
  return wyn;
}

zespol zesp_sprzez(zespol z)
{
  zespol wyn;
  wyn.ima=-z.ima;
  return wyn;
}

double zesp_abs(zespol z)
{
  double wyn;
  wyn=sqrt(z.rea*z.rea+z.ima*z.ima);
  return wyn;
}

int main()
{
  zespol z1, z2;
  printf("Z1 == "); z1 = zesp_get();
  printf("Z2 == "); z2 = zesp_get();
  printf("\nZ1+Z2 == "); zesp_print(zesp_dodac(z1, z2));
  printf("\nZ1-Z2 == "); zesp_print(zesp_odjac(z1, z2));
  printf("\nZ1*Z2 == "); zesp_print(zesp_razy(z1, z2));
  printf("\n|Z1+Z2| == %.4lf\n", zesp_abs(zesp_dodac(z1, z2)));
}
