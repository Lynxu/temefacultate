#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a[40],inv=0,cop,k=0,nr;
    printf("Introduceti n: "); scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        printf("a[%i]=",i);
        scanf("%i",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        inv=0;
        nr=a[i];
        cop=a[i];
        while(nr)
        {
            inv=inv*10+nr%10;
            nr/=10;
        }
        if(inv==cop) k++;
    }
    printf("%i",k);
    return 0;
}
