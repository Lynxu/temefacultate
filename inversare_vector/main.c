#include <stdio.h>
#include <stdlib.h>

void citire(int n,int a[40]);
void tiparire(int n, int a[40]);
void inversare(int n, int a[40]);

int main()
{
    int n,a[40];
    printf("Introduceti n: "); scanf("%i",&n);
    citire(n,a);
    afisare(n,a);
    inversare(n,a);
    afisare(n,a);
    return 0;
}

void citire(int n, int a[40])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("a[%i]=",i);
        scanf("%i",&a[i]);
    }
}

void afisare(int n,int a[40])
{
    int i;
    for(i=0;i<n;i++)
        printf("%i ",a[i]);
        printf("\n");
}

void inversare(int n, int a[40])
{
    int i,aux;
    for(i=0;i<n/2;i++)
    {
        aux=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=aux;
    }
}
