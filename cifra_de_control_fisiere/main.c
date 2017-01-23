#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,s=0;
    FILE *f=fopen("numar.txt","r");
    fscanf(f,"%i",&n);
    while(n>9)
    {
        s+=n%10;
        n=n/10;
        if(n<10)
        {
            n+=s;
            s=0;
        }
    }
    printf("cifra de control este %i",n);
    return 0;
}
