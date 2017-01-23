#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i,j,p;
    FILE *f=fopen("prime.txt","w+");
    printf("Introduceti n: ");scanf("%i",&n);
    for(i=2;i<=n;i++)
    {
        p=1;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                p=0;
        }
        if(p==1)
            fprintf(f,"%i " , i);
    }
    fclose(f);
    return 0;
}
