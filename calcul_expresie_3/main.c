#include <stdio.h>
#include <stdlib.h>

float expresie(int n)
{
    int i;
    float p=1,d;
    for(i=1;i<=n;i++)
        if(!(i%2))
        {
            d=1/(float)i;
            p=p*d;
        }
    else p*=i;
    return p;
}

int main()
{
    int n;
    printf("Introduceti n: "); scanf("%i",&n);
    printf("Rezultatul expresiei pentru primele %i numere este : %.2f",n,expresie(n));
    return 0;
}
