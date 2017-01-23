#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,p=1;
    FILE *f=fopen("prim.txt","r");
    fscanf(f,"%i",&n);
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
            p=0;
    if(p==1)
        printf("Nr este prim");
    else
        printf("Nr nu est prim");
    return 0;
}
