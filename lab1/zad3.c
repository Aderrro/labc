#include<stdio.h>

void wypisz(int tab[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", tab[i++]);
	}
	printf("\n");
}

int main()
{
	int tmp, a=2;
	int tab1[5]={1, 2, 3, 4, 5};
	int tab2[5]={1, 2, 3, 4, 5};
	tmp=a;
  	tab1[a++]=0;
  	a=tmp;
	tab2[++a]=0;
	wypisz(tab1, 5);
	wypisz(tab2, 5);
	
	int y,z,x=10;
	y=(x+=2);
	z=(x%=3)+(x%=4);
	printf("x=%d, y=%d, z=%d\n", x, y, z);
	
	return 0;
	
	
}
