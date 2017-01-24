#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,s=0;
    FILE *f=fopen("numar.txt","r");
    fscanf(f,"%i",&n);
    for(i=1;i<=n/2;i++)
        if(n%i==0)
            s+=i;
    if(s==n)
        printf("Numarul este perfect!");
    else
        printf("Numarul nu este perfect!");
    fclose(f);
    return 0;
}
