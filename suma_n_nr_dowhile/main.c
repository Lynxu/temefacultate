#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=1,s=0;
    printf("Introduceti n: "); scanf("%i",&n);
    do
    {
        s+=i;
        i++;
    }while(i<=n);
    printf("Suma primelor %i numere este: %i \n",n,s);
    return 0;
}
