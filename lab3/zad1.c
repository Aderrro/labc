#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
  printf("Wybierz typ aby uzyskac informacje :\n");
  printf("1.SHORT\n");
  printf("2.INT\n");
  printf("3.LONG\n");
  printf("4.LONG LONG\n");
  printf("5.FLOAT\n");
  printf("6.DOUBLE\n");
  printf("7.LONG DOUBLE\n");
  int opcja;
  scanf("%i", &opcja);

  	switch(opcja)
	{
    		case 1:
    		printf("SHORT\n");
    		printf("Wartosc dolna : %i\n", SHRT_MIN);
    		printf("Wartosc gorna : %i\n", SHRT_MAX);
    		printf("Ziarno : - \n");
    		printf("Precyzja : -\n");
    		break;

    		case 2:
    		printf("INT\n");
    		printf("Wartosc dolna : %i\n", INT_MIN);
    		printf("Wartosc gorna : %i\n", INT_MAX);
    		printf("Ziarno : - \n");
    		printf("Precyzja : -\n");
    		break;

   		case 3:
   		printf("LONG\n");
   		printf("Wartosc dolna : %li\n", LONG_MIN);
   		printf("Wartosc gorna : %li\n", LONG_MAX);
   		printf("Ziarno : - \n");
    		printf("Precyzja : -\n");
    		break;

    		case 4:
    		printf("LONG LONG\n");
   		printf("Wartosc dolna : %lli\n", LLONG_MIN);
    		printf("Wartosc gorna : %lli\n", LLONG_MAX);
    		printf("Ziarno : - \n");
    		printf("Precyzja : -\n");
    		break;

    		case 5:
    		printf("FLOAT\n");
    		printf("Wartosc dolna : %e\n", FLT_MIN);
    		printf("Wartosc gorna : %e\n", FLT_MAX);
    		printf("Ziarno : %e\n", FLT_EPSILON);
    		printf("Precyzja : %i\n", FLT_DIG);
    		break;

    		case 6:
    		printf("DOUBLE\n");
    		printf("Wartosc dolna : %le\n", DBL_MIN);
    		printf("Wartosc gorna : %le\n", DBL_MAX);
    		printf("Ziarno : %e\n", DBL_EPSILON);
    		printf("Precyzja : %i\n", DBL_DIG);
    		break;

    		case 7:
    		printf("LONG DOUBLE\n");
    		printf("Wartosc dolna : %Le\n", LDBL_MIN);
    		printf("Wartosc gorna : %Le\n", LDBL_MAX);
    		printf("Ziarno : %e\n", LDBL_EPSILON);
    		printf("Precyzja : %i\n", LDBL_DIG);
    		break;

    		default:
    		printf("Nie ma takiej opcji!");
    		break;
	}
}
