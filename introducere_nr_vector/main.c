#include <stdio.h>
#include <stdlib.h>

void citire(int a[40],int* n);
void introducere(int a[40], int n);

int main()
{
    int n, a[40];
    printf("Introduceti n: "); scanf("%i",&n);
    citire(a,&n);
    introducere(a,n);
    return 0;
}

void citire(int a[40],int* n)
{
    int i;
    for(i=0;i<*n;i++)
    {
        printf("a[%i]=",i);
        scanf("%i",&a[i]);
    }
}

void introducere(int a[40], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%i ",a[i]);
}
