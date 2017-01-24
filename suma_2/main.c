#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    float aux,s=0;
    FILE *f=fopen("suma.txt","w+");
    printf("Introduceti n: "); scanf("%i",&n);
    for(i=2;i<=n;i++)
        {
            aux=i;
            s=s+aux/((aux-1)*(aux+1));
        }
    fprintf(f,"%f",s);
    return 0;
}
