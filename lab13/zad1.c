#include <stdio.h>

int main()
{
    int m, n, x, y;

    printf("Podaj ilosc wierszy macierzy :\n");
    scanf("%d", &m);
    printf("Podaj ilosc kolumn macierzy :\n");
    scanf("%d", &n);
    int macierz[m][n], transpozycja[m][n];

    printf("Podaj elementy macierzy\n");

    for (y = 0; y < m; y++)
        for(x = 0; x < n; x++)
            scanf("%d",&macierz[y][x]);

    for (y = 0; y < m; y++)
        for( x = 0 ; x < n ; x++ )
            transpozycja[x][y] = macierz[y][x];

    printf("\nMacierz:\n");
    for (y = 0; y < m; y++)
    {
        for(x = 0; x < n; x++)
        {
            printf("%d ", macierz[y][x]);
        }
        printf("\n");
    }

    printf("\nTranspozycja macierzy:\n");

    for (y = 0; y < n; y++)
    {
        for (x = 0; x < m; x++)
            printf("%d ",transpozycja[y][x]);
        printf("\n");
    }

    return 0;
}
