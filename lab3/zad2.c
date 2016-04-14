#include <stdio.h>

int main()
{
  short s=32767;
  short se=s+1;
  printf("Short: %i + 1 = %i\n", s, se);

  int i=2147483647;
  int ie=i+1;
  printf("Int: %i + 1 = %i\n", i, ie);

  long l=9223372036854775807;
  long le=l+1;
  printf("Long: %li + 1 = %li\n", l, le);

  long ll=9223372036854775807;
  long lle = ll+1;
  printf("Long long: %li + 1 = %li\n", ll, lle);

  float fl=0.000001;
  float fle=fl/2.0;
  printf("Float: %f / 2 = %f\n", fl, fle);

  double d=0.000001;
  double de=d/2.0;
  printf("Double: %f / 2 = %f\n", d, de);

  long double ld=0.000001;
  long double lde=ld/2.0;
  printf("Long double: %Lf / 2 = %Lf\n", ld, lde);
  return 0;
}
