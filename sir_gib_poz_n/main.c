#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,j,k=1,a=0,b=1,c=1;
    printf("Introduceti n: "); scanf("%i",&n);
    while(c<=n)
    {
        c=a+b;
        a=b;
        b=c;
        k++;
    }
   if(c==n){printf("%d apartine fib si este pe poz %d",c,k);}
     else printf(" nr nu apartine");

    return 0;
}
