#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,nr,i,j,s=0,p=1;
    printf("Introduceti n:"); scanf("%i",&n);
    for(i=1;i<=n;i++)
        {
            printf("Introduceti nr: "); scanf("%i",&nr);
            if(n)
                s=s*10+nr%10;
        }
        for(j=2;j<=s/2;j++)
            if(s%i==0)
                p=0;
        printf("%i\n",s);
        if(p==1)
            printf("Nr este prim!");
        else printf("Nr nu este prim!");
    return 0;
}
