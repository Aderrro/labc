#include <stdio.h>
#include <stdlib.h>

void print_tab(int *ile, char *arg[], char *jakis)
{
    int i;
    for(i=*ile-1; i>0; i--)
    {
        if(i!=1)
        {
            printf("%s", arg[i]);
            printf("%c", *jakis);
        }
        else
        {
            printf("%s\n", arg[i]);
        }
    }
}

int main (int ile_arg, char* arg[ ])
{
    printf("Podaj separator! :\n");
    char c;
    c = getchar();
    print_tab(&ile_arg, arg,&c);
    return 0;
}
