#include <stdio.h>
int main()
{
	int a,b,c,d;
	a=b=c=d=0;
	printf("%d %d %d %d\n", a, b, c, d);
	// a, b, c, d = 0

	printf("\n");

	int i,N=10;
	int tab[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(i=0;i<N;tab[i++]=i)
	printf("%d ", tab[i]);
	// indeks "i" tablicy "tab[]" przyjmuje wartosc "i" nastepnie zwieksza sie o jeden (postinkrementacja)

	printf("\n");

	for(i=0;i<N;tab[++i]=i)
	printf("%d ", tab[i]);
	// indeks 'i' tablicy "tab[]" zwieksza sie o jeden (preinkrementacja) nastepnie przyjmuje wartosc "i"

	printf("\n");

	i=1;
	while((i*=2)<N);
	printf("%d\n", i);
	// Dopoki i mniejsze od N ( = 10) mnozone przez dwa
	return 0;
}
