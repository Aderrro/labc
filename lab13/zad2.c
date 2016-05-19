#include <stdio.h>

int main()
{
    int m, n, p, q, y, x, k, sum = 0;

    printf("Wprowadz liczbe wierszy pierwszej macierzy:\n");
    scanf("%d", &m);
    printf("Wprowadz liczbe kolumn pierwszej macierzy:\n");
    scanf("%d", &n);
    int pierwsza[m][n];
    printf("Wprowadz elementy pierwszej macierzy:\n");

    for (y = 0; y < m; y++)
        for (x = 0; x < n; x++)
            scanf("%d", &pierwsza[y][x]);
    printf("\nMacierz pierwsza:\n");
    for (y = 0; y < m; y++)
    {
        for(x = 0; x < n; x++)
        {
            printf("%d ", pierwsza[y][x]);
        }
        printf("\n");
    }

    printf("Wprowadz liczbe wierszy drugiej macierzy:\n");
    scanf("%d", &p);
    printf("Wprowadz liczbe kolumn drugiej macierzy:\n");
    scanf("%d", &q);
    int druga[p][q];
    int mnozenie[m][q];



    if (n != p)
        printf("Macierze nie moga byc pomnozone! Ilosc kolumn jest rozna!\n");
    else
    {
        printf("Wprowadz ilosc elementow drugiej macierzy:\n");

        for (y = 0; y < p; y++)
            for (x = 0; x < q; x++)
                scanf("%d", &druga[y][x]);

        printf("\nMacierz druga:\n");
        for (y = 0; y < p; y++)
        {
            for(x = 0; x < q; x++)
            {
                printf("%d ", druga[y][x]);
            }
            printf("\n");
        }

        for (y = 0; y < m; y++)
        {
            for (x = 0; x < q; x++)
            {
                for (k = 0; k < p; k++)
                {
                    sum = sum + pierwsza[y][k]*druga[k][x];
                }
                mnozenie[y][x] = sum;
                sum = 0;
            }
        }

    printf("Wynik mnozenia macierzy: \n");

    for (y = 0; y < m; y++) {
      for (x = 0; x < q; x++)
        printf("%d\t", mnozenie[y][x]);

      printf("\n");
    }
  }

  return 0;
}
