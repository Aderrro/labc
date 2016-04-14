#include<stdio.h>

int odszyf(int n)
{
  return -n;
}

void druk(int n)
{
  int i;
  int buf[4];
  for(i=0; i<4; i++)
  {
    buf[i]= n&255;
    n>>=8;
  }
  for(i=3; i>=0; i--)
  {
    printf("%c", (char)buf[i]);
  }
}

int main()
{
  int n, load;
  load = scanf("%i", &n);
  while (load == 1)
  {
    druk(odszyf(n));
    load=scanf("%i", &n);
  }
  return 0;
}
