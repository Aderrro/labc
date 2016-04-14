#include <stdio.h>

void data(int n);

int main()
{
  int n;
  scanf("%i", &n);
  data(n);
  return 0;
}

void data(int n)
{
  int tab[32];
  int i, j=0, dwa=1;
  int r=0, m=0, d=0;

  while(n!=0)
  {
    tab[j]=n%2;
    n=n/2;
    j++;
  }

  for(i=0;i<5;i++)
  {
    d+=tab[i]*dwa;
    dwa*=2;
  }
  if(d==0) d=1;
  dwa=1;

  for(i=5;i<9;i++)
  {
    m+=tab[i]*dwa;
    dwa*=2;
  }
  if(m==0) m=1;
  if(m>12) m=12;
  dwa=1;

  for(i=9;i<j;i++)
  {
    r+=tab[i]*dwa;
    dwa*=2;
  }
  printf("%i.%i.%i\n", d, m, r);
}
