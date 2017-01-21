#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c; float x1,x2,d;
    printf("a=");scanf("%i",&a);
    printf("b=");scanf("%i",&b);
    printf("c=");scanf("%i",&c);
    if(!a)
        if(!b)
            if(!c)
                printf("Ecuatia are o infinitate de solutii");
            else
                printf("Ecuatia nu are solutii");
        else
        {
            x1=-c/(float)b;
            printf("Solutia ecuatiei este:%f ",x1);
        }
    else
    {
        d=b*b-4*a*c;
        if(d<0)
            printf("Ecuatia nu are solutii reale");
        else if(!d)
        {
            x1=-c/(float)b;
            printf("Solutia ecuatiei este %f",x1);
        }
        else
        {
            x1=(-b+sqrt(d))/2*a;
            x2=(-b-sqrt(d))/2*a;
            printf("Solutiile ecuatiei sunt x1=%f , x2=%f",x1,x2);
        }
    }
    return 0;
}
