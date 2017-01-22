#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=i;
    return p;
}

int main()
{
    int n,i,m,s=0;
    printf("Introduceti n : "); scanf("%i",&n);
    for(i=1;i<=n;i++)
        s+=factorial(i);
    printf("Suma factorialelor este : %i",s);

    return 0;
}
