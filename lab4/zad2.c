/*
Ten sam program wzbogadzic o tozsamosc Eulera
*/

/* gcc -Wall zad1.c -o zad1 -lm */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <complex.h>


//"struktura" liczby zespolonej :
typedef struct
{
  double rea, ima;
} zespol;

/*
pomocnicza funkcja przy uzyskaniu błedu wywołana w elsie (w funkcji zespol zesp_get(void), 
gdy uzytkownik niepoprawnie wpisze postac liczby zespolonej.
*/

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
  /* wczytanie liczby zespolonej; 
  w postaci (X + Yi), gdzie X, Y - rzeczywiste, dopisanie "i" wymagane (liczba imaginalis) */
  char ch;
  zespol z;
  int znak_im;
  do{ch=getchar();} while(isspace(ch));
  if(ch=='(')
  {
    if(scanf("%lf", &(z.rea))==1)
    {
      do{ch = getchar();} while(isspace(ch));
      if(ch=='+' || ch=='-')
      {
        if(ch=='+') znak_im=1;
        else znak_im=-1;
        if(scanf("%lf", &(z.ima))==1)
        {
          do{ch=getchar();} while(isspace(ch));
          if(ch=='i')
          {
            do{ch=getchar();} while(isspace(ch));
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

/*
Postac liczb zespolonych :
z1 = a + bi;
z2 = c + di;
gdzie a, b, c, d sa rzeczywiste

Wykorzystane wzory do utworzenia funkcji : 
- Dodawanie : z1 + z2 = (a + c) + (b + d)i;
- Odejmowanie : z1 - z2 = (a - c) + (b - d)i;
- Mnożenie : z1 * z2 = (ac - bd) + (ad + bc)i;
- Sprzezenie : z1S = a - bi;
- Moduł : |z| = |a + bi| = sqrt/pierwiastek (a^2 + b^2);
*/


// dodawanie liczb zespolonych  :
zespol zesp_dodac(zespol z1, zespol z2)
{
  zespol wynik;
  wynik.rea=z1.rea+z2.rea;
  wynik.ima=z1.ima+z2.ima;
  return wynik;
}

// odejmowanie liczb zespolonych :
zespol zesp_odjac(zespol z1, zespol z2)
{
  zespol wynik;
  wynik.rea=z1.rea-z2.rea;
  wynik.ima=z2.ima-z2.ima;
  return wynik;
}

// mnozenie liczb zespolonych :
zespol zesp_razy(zespol z1, zespol z2)
{
  zespol wynik;
  wynik.rea=z1.rea*z2.rea-z1.ima*z2.ima;
  wynik.ima=z1.rea*z2.ima+z1.ima*z2.rea;
  return wynik;
}

// liczba sprzezona do danej zespolonej :
zespol zesp_sprzez(zespol z)
{
  zespol wynik;
  wynik.ima=-z.ima;
  return wynik;
}

//dzielenie liczby zespolonej
zespol zesp_dziel(zespol z1, int dzielnik)
{
  zespol wyn;
  wyn.rea=z1.rea/dzielnik;
  wyn.ima=z1.ima/dzielnik;
  return wyn;
}

// wartosc bezwzgledna liczby zespolonej , tzw. "moduł":
double zesp_abs(zespol z)
{
  double wynik;
  wynik=sqrt(z.rea*z.rea+z.ima*z.ima);
  return wynik;
}
// dodatkowe funkcje do sprawdzenia tozsamosci :
zespol euler()
{
  zespol z;
  z.rea=cos(M_PI);
  z.ima=sin(M_PI);
  return z;
}

zespol jeden()
{
  zespol jeden;
  jeden.rea=1;
  jeden.ima=0;
  return jeden;
}

zespol zero()
{
  zespol zero;
  zero.rea=0;
  zero.ima=0;
  return zero;
}

zespol zesp_exp(zespol z)
{
  zespol wynik=zero();
  zespol temp=jeden();
  int i;
  for(i=1;i<1000000;i++)
  {
    wynik=zesp_dodac(wynik, temp);
    temp=zesp_dziel(zesp_razy(temp, z), i);
  }
  return wynik;
}


int main()
{
  zespol z1, z2;
  zespol Eul=euler();
  zespol O=jeden();
  zespol PII={0.0, M_PI};
  zespol final=zesp_dodac(zesp_exp(PII), O);
  printf("Zespolona Z1 == "); z1 = zesp_get();
  printf("Zespolona Z2 == "); z2 = zesp_get();
  printf("\nZ1+Z2 == "); zesp_print(zesp_dodac(z1, z2));
  printf("\nZ1-Z2 == "); zesp_print(zesp_odjac(z1, z2));
  printf("\nZ1*Z2 == "); zesp_print(zesp_razy(z1, z2));
  printf("\n|Z1+Z2| == %.4lf\n", zesp_abs(zesp_dodac(z1, z2)));
  printf("\n\n");
  
  printf("Tozsamosc Eulera: \n");
  zesp_print(Eul);
  printf(" + ");
  zesp_print(O);
  printf(" = ");
  zesp_print(zesp_dodac(Eul, O));
  printf("\n");
  zesp_print(zesp_exp(Eul));
  printf("\n");
  zesp_print(final);
  printf("\n");
  return 0;
}
