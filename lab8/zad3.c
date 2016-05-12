#include <stdio.h>

#define CZYT(liczba, typ)\
 printf("Podaj wartosc "#liczba": ");\
 scanf("%"#typ, &liczba);

int main ()
{
  int x;
  double y;
  CZYT(x, i);
  CZYT(y, lf);
  printf("%i\n", x);
  printf("%lf\n", y);
}
