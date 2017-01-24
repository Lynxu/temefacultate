#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=1,a=0,b=1,c;
    printf("Introduceti n: "); scanf("%i",&n);
    if(n==0)
        printf("%i",a);
    else if(n==1)
            printf("%i",b);
    else while(n>i)
            {
                c=b+a;
                a=b;
                b=c;
                i++;
            }
    printf("%i",c);
    return 0;
}
