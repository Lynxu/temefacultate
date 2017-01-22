#include <stdio.h>
#include <stdlib.h>

void citire(int n, int a[40]);
int suma (int n, int a[40]);

int main()
{
    int n,a[40];
    printf("Introduceti n : "); scanf("%i",&n);
    citire(n,a);
    printf("%i",suma(n,a));
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

int suma(int n, int a[40])
{
    int i,s=0;
    for(i=0;i<n;i++)
        s+=a[i];
    return s;
}
