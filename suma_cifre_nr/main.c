#include <stdio.h>
#include <stdlib.h>

int suma_cifre(int n)
{
    int s=0;
    while(n)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}

int main()
{
    int n;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("s=%i",suma_cifre(n));
    return 0;
}
