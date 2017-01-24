#include <stdio.h>
#include <stdlib.h>

void citire(int n,int a[40]);
int cautare (int n,int nr, int a[40]);

int main()
{
    int n,a[40],nr;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("Introduceti nr: "); scanf("%i",&nr);
    citire(n,a);
    printf("%i",cautare(n,nr,a));
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

int cautare(int n,int nr, int a[40])
{
    int i,k=0;
    for(i=0;i<n;i++)
        if(nr==a[i])
            k++;
    return k;
}
