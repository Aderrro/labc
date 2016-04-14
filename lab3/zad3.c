#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  printf("FLT_MAX -> (int)FLT_MAX:\n%e -> %i\n\n", FLT_MAX, (int)FLT_MAX);
  printf("INT_MAX -> (float)INT_MAX:\n%i -> %e\n\n", INT_MAX, (float)INT_MAX);
  printf("DBL_MAX -> (int)DBL_MAX:\n%e -> %i\n\n", DBL_MAX, (int)DBL_MAX);
  printf("Wartosc double max wychodzi poza maksymalna wartosc inta, zatem drukowana jest wartosc maksymalna inta.\n");
  printf("INT_MAX -> (double)INT_MAX:\n%i -> %e\n\n", INT_MAX, (double)INT_MAX);
  printf("LDBL_MAX -> (double)LDBL_MAX:\n%Le -> %e\n\n", LDBL_MAX, (double)LDBL_MAX);
  printf("LONG_MAX -> (float)LONG_MAX:\n%li -> %e\n\n", LONG_MAX, (float)LONG_MAX);
  printf("INT_MAX -> (float)INT_MAX:\n%i -> %e\n\n", INT_MAX, (float)INT_MAX);
  return 0;
}
