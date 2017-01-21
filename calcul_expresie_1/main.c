#include <stdio.h>
#include <stdlib.h>

int suma(int n)
{
    int s=0,i,semn=1;
    for(i=1;i<=n;i++)
    {
        s+=semn*i;
        semn=-semn;
    }
    return s;
}


int main()
{
    int n;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("Calculul este egal cu: %i",suma(n));
    return 0;
}
