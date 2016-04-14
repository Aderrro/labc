#include <stdio.h>

void binary(int x);

int main()
{
  char z;
  z=getchar();
  while(z!=EOF)
  {
    if(z!='\n') binary(z);
    z=getchar();
  }
  return 0;
}

void binary(int x)
{
  int tab[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int i=0;
  int n=8;
  while(x!=0)
  {
    tab[i]=x%2;
    x=x/2;
    i++;
  }
  while(n>0)
  {
    n--;
    printf("%i", tab[n]);
  }
  printf("\n");
}
