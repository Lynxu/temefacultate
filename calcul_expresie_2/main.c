#include <stdio.h>
#include <stdlib.h>

int expresie(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=i;
    return p;
}


int main()
{
    int n;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("Produsul primelor %i numere este: %i",n,expresie(n));
    return 0;
}
