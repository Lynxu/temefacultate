#include <stdio.h>
#include <stdlib.h>

void citire(int n, int a[40]);
int min(int n,int a[40]);
int max(int n,int a[40]);

int main()
{
    int n,a[40];
    printf("Introduceti n : "); scanf("%i",&n);
    citire(n,a);
    printf("min=%i\n",min(n,a));
    printf("max=%i", max(n,a));
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

int min(int n, int a[40])
{
    int i,mi=sizeof(int);
    for(i=0;i<n;i++)
        if(a[i]<mi)
            mi=a[i];
    return mi;
}

int max(int n, int a[40])
{
    int i,ma=0;
    for(i=0;i<n;i++)
        if(a[i]>ma)
            ma=a[i];
    return ma;
}
