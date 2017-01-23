#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0;
    FILE *f;
    do
    {
        printf("Introduceti n: "); scanf("%i",&n);
        s+=n;
    }while(n!=0);
    f=fopen("suma.txt","w+");
    fprintf(f,"s=%i",s);
    fclose(f);
    return 0;
}
