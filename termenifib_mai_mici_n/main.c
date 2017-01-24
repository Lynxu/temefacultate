#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,b=1,c=1,n,i;
    printf("introduceti n :"); scanf("%i",&n);
    if(n==0)
        printf("%i",n);
    else
        if(n==1)
            printf("%i",n);
    else
    while(c<n)
    {
        c=a+b;
        a=b;
        b=c;
       if(c<=n) printf("%i",c);
    }
    return 0;
}
