#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<time.h>

#define IMIE_MAX 20
#define NAZW_MAX 20
#define IL_OSOB 10000

typedef struct {
    char imie[IMIE_MAX+1];
    char nazwisko[NAZW_MAX+1];
    int pensja;
} osoba;

osoba spis[IL_OSOB];

//=======================================================

void utworz_spis(char *name, int *linie)
{
    FILE *baza = fopen(name, "r");
    if (baza == NULL)
	printf("\nCOS SIE ZEPSULO!\n\n");
    int i;
    for (i = 0; i < *linie; i++) {
	fscanf(baza, "%s", spis[i].imie);
	fscanf(baza, "%s", spis[i].nazwisko);
	fscanf(baza, "%i", &spis[i].pensja);
    }
    fclose(baza);
}

//=======================================================

int ilosc_linii(char *name)
{
        int linie = 0;
        FILE* plik;
        plik = fopen(name, "r");
        int w;
        do{
                fscanf(plik, "%s", spis[linie].imie);
                fscanf(plik, "%s", spis[linie].nazwisko);
        w =     fscanf(plik, "%i", &spis[linie].pensja);
        linie++;
        }while(w  != EOF);
        fclose(plik);
        return linie-1;
}

//=======================================================

int my_compare(const void *a, const void *b)
{
    osoba *osoba_a, *osoba_b;
    osoba_a = (osoba *) a;
    osoba_b = (osoba *) b;

    return strcmp(osoba_a->nazwisko, osoba_b->nazwisko);
}

//=======================================================
void sortuj_qsort(int *linie)
{
    qsort(spis, *linie, sizeof(osoba), my_compare);
    FILE *baza2 = fopen("qsort.txt", "w");
    int i;
    for (i = 0; i < *linie; i++) {
	fprintf(baza2, "%20s	", spis[i].imie);
	fprintf(baza2, "%20s	", spis[i].nazwisko);
	fprintf(baza2, "%20i\n", spis[i].pensja);
    }
    fclose(baza2);
}

//=======================================================


void sortuj_bubble(int *linie)
{
  int i, j;
  char pom[NAZW_MAX+1];
  for(i=1;i<=*linie;i++)
  {
    for(j=i;j<*linie;j++)
    {
      if(strcmp(spis[j-1].nazwisko, spis[j].nazwisko)>0)
      {
        strcpy(pom, spis[j-1].nazwisko);
        strcpy(spis[j-1].nazwisko, spis[j].nazwisko);
        strcpy(spis[j].nazwisko, pom);
      }
      else if(strcmp(spis[j-1].nazwisko,spis[j].nazwisko)==0)
      {
        strcpy(pom,spis[j-1].imie);
        strcpy(spis[j-1].imie, spis[j].imie);
        strcpy(spis[j].imie, pom);
      }
    }
  }
  FILE* baza3=fopen("bubblesort.txt","w");
  for(i=0;i<*linie;i++)
  {
	fprintf(baza3, "%20s	", spis[i].imie);
	fprintf(baza3, "%20s	", spis[i].nazwisko);
	fprintf(baza3, "%20i\n", spis[i].pensja);
  }
  fclose(baza3);
}


//=======================================================

int main (int ile_arg, char* arg[])
{
 if(ile_arg == 2)
 {
  char nazwa[100];
  sscanf(arg[1], "%s", nazwa);
  int ilosc;
  ilosc = ilosc_linii(nazwa);
  if(ilosc > IL_OSOB)
  {
    printf("Za duzo osob! Nie dam rady!\n");
    return 0;
  }
  printf("Zeskanowalem %i linii z pliku %s\n", ilosc, arg[1]);
  utworz_spis(nazwa, &ilosc);
  //czas qsorta :
  clock_t  pocz1 = clock();
  sortuj_qsort(&ilosc);
  clock_t  koniec1 = clock();
  printf("\nCzas wykonania qsorta: %lf sek.\n\n",
         (double)(koniec1-pocz1) / CLOCKS_PER_SEC
        );
  double roznica1;
  roznica1 = (double)(koniec1-pocz1) / CLOCKS_PER_SEC;
  //czas bubble'a :
  clock_t  pocz2 = clock();
  sortuj_bubble(&ilosc);
  clock_t  koniec2 = clock();
  printf("\nCzas wykonania bubble: %lf sek.\n\n",
         (double)(koniec2-pocz2) / CLOCKS_PER_SEC
        );
  double roznica2;
  roznica2 = (double)(koniec2-pocz2) / CLOCKS_PER_SEC;
        
  printf("|%15s|%15s|\n", "SORTOWANIE", "CZAS");
  printf("|---------------|---------------|\n");
  printf("|%15s|%15le|\n", "QSORT", roznica1);
  printf("|%15s|%15le|\n", "BUBBLESORT", roznica2);
  
  
  
  

  printf("\nPosortowane!\n\n");
  return 0;
 }
 else
    printf("\nNiepoprawne wywolanie programu!\n");
    printf("Wywolanie programu wymaga argumentu!\n");
    printf("./zad2b nazwapliku(lub lokalizacja pliku)!\n");
 return 0;
}
