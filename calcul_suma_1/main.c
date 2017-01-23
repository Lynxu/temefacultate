#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    float s=0,p=1;
    FILE *f=fopen("numar.txt","r");
    fscanf(f,"%i",&n);
    for(i=1;i<=n;i++)
        {
            p*=i;
            s+=1/p;
        }
    printf("suma=%f",s);
    fclose(f);
    return 0;
}
