#include<stdio.h>

int klucz(int n)
{
  return -n;
}

int szyfr(int buf[4])
{
  int i;
  int j=0;
  for (i=0; i<4; i++)
  {
    j=(j<<8)|(buf[i]&255);
  }
  return j;
}

int main()
{
  int buf[4];
  int i;
  int j=0;
  buf[j]=(int)getchar();
  while(buf[j]!=EOF)
  {
    j++;
    if(j=4)
    {
      printf("%i ", klucz(szyfr(buf)));
      j=0;
    }
    buf[j]=(int)getchar();
  }
  if(j>0)
  {
    for(i=j;i<4; i++) buf[i]=' ';
    printf("%i ", klucz(szyfr(buf)));
  }
  printf("\n");
  return 0;
}
