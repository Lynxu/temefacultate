#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0,inv=0;
    printf("Introduceti n: "); scanf("%i",&n);
    while(n)
    {
        s+=n%10;
        inv=inv*10+n%10;
        n/=10;
    }
    printf("Suma=%i , inversul %i",s,inv);
    return 0;
}
