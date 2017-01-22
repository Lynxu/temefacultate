#include <stdio.h>
#include <stdlib.h>

int expresie(int n)
{
    int s=0,p=1,i;
    for(i=1;i<=n;i++)
    {
        p*=i;
        s+=p;
    }
    return s;
}


int main()
{
    int n;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("Rezultatul expresiei este : %i",expresie(n));
    return 0;
}
