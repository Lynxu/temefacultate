#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,s=0;
    printf("Introduceti n: "); scanf("%i",&n);
    for(i=1;i<=n;i++)
        s+=i;
    printf("Suma primelor %i numere este: %i \n",n,s);
    return 0;
}
