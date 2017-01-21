#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0,i=1;
    printf("Introduceti n: "); scanf("%i",&n);
    while(i<=n)
    {
        s+=i;
        i++;
    }
    printf("Suma primelor %i numere este: %i\n",n,s);
    return 0;
}
