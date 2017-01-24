#include <stdio.h>
#include <stdlib.h>


void citire(int n, int a[40]);
int minim(int n, int a[40]);

int main()
{
    int n,a[40];
    printf("Introduceti n:"); scanf("%i",&n);
    citire(n,a);
    printf("%i",minim(n,a));
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


int minim(int n,int a[40])
{
    int i,min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
            min=a[i];
    }
    return min;
}
