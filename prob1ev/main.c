#include <stdio.h>
#include <stdlib.h>

unsigned int cmmdc(unsigned int a, unsigned int b)
{
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;

}

int nr_perfect(unsigned int x)
{
    int i, S=1;
    for(i=2; i<x; i++)
        if(x%i == 0)
            S+=i;
    if(S==x)
        return 1;
    else
        return 0;

}

int main()
{
    FILE *f; unsigned int a,b;
    f=fopen("numere.txt","r");
    fscanf(f,"%i %i",&a, &b);
    if (nr_perfect(cmmdc(a, b)))
        printf("Cel mai mare divizor comun al numerelor %i si %i \
               este numar perfect!", a, b);
    else
        printf("Cel mai mare divizor comun al numerelor %i si %i \
               este numar perfect!", a, b);
    fclose(f);
    return 0;
}

