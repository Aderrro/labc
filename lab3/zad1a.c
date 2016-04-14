#include<stdio.h>
#include<float.h>
#include<limits.h>

int main()
{
  printf("|%11s|%21s|%21s|%13s|%12s|\n", "TYP", "MINIMUM", "MAXIMUM", "ZIARNO", "PRECYZJA");
  printf("|-----------|---------------------|---------------------|-------------|------------|\n");
  // short
  printf("|%11s|%21i|%21i|%13c|%12c|\n", "SHORT", (short)SHRT_MIN, (short)SHRT_MAX, ' ', ' ');
  // int
  printf("|%11s|%21d|%21d|%13c|%12c|\n", "INT", (int)INT_MIN, (int)INT_MAX, ' ', ' ');
  // long
  printf("|%11s|%21li|%21li|%13c|%12c|\n", "LONG", (long)LONG_MIN, (long)LONG_MAX, ' ', ' ');
  // long long
  printf("|%11s|%21lli|%21lli|%13c|%12c|\n", "LONG LONG", (long long)LLONG_MIN, (long long)LLONG_MAX, ' ', ' ');
  // float
  printf("|%11s|%21e|%21e| %e| %11d|\n", "FLOAT", (float)FLT_MIN, (float)FLT_MAX, FLT_EPSILON, (int)FLT_DIG);
  // double
  printf("|%11s|%21le|%21le| %e| %11d|\n", "DOUBLE", (double)DBL_MIN, (double)DBL_MAX, DBL_EPSILON, (int)DBL_DIG);
  // long double
  printf("|%11s|%21Le|%21Le| %Le| %11d|\n", "LONG DOUBLE", (long double)LDBL_MIN, (long double)LDBL_MAX, LDBL_EPSILON, (int)LDBL_DIG);


return 0;
}
