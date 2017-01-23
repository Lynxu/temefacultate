#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0;
    FILE *f=fopen("numar.txt","r");
    FILE *g=fopen("suma.txt","w+");
    fscanf(f,"%i",&n);
    while(n>0)
    {
        s=s+n%10;
        n=n/10;
    }
    fprintf(g,"s=%i",s);
    fclose(f);
    fclose(g);
    return 0;
}
