#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Introduceti a: " ); scanf("%i",&a);
    printf("Introduceti b: "); scanf("%i",&b);
    while(a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;
    printf("cmmdc=%i",a);
    return 0;
}
