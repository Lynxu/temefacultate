#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,v[40],j,nr=0,p;
    printf("Introduceti n: "); scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        printf("v[%i]=",i);
        scanf("%i",&v[i]);
    }
    for(i=0;i<n;i++)
    {
        p=1;
        if(v[i]<2)
            p=0;

        for(j=2;j<=sqrt(v[i]);j++)
            if(v[i]%j==0)
                p=0;
        if(p==1) nr++;}
            printf("%i",nr);
    return 0;
}
