#include<stdio.h>

void il_mod(int *q, int *r, int a, int b);

int main()
{
	int n, k, r, q;
	printf("Podaj liczbe calkowita 'n' : ");
	scanf("%i", &n);
	printf("Podaj liczbe calkowita 'k', k=/=0 : ");
	scanf("%i", &k);
	if(k == 0)
	{
		printf("Bledna wartosc 'k'! Uruchom ponownie!\n");
		return 0;
	}
	il_mod(&q, &r, n, k);
	printf("Iloraz calkowity : %i\n", q);
	printf("Reszta z dzielenia : %i\n", r);
	return 0;
}

void il_mod(int *q, int*r, int a, int b)
{
	*q = a/b;
	*r = a%b;
}

