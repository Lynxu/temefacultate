#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,aux,oglindit;
    FILE *f=fopen("numere.txt","r");
    FILE *g=fopen("palindrom.txt","w+");
    fscanf(f,"%i",&a);
    fscanf(f,"%i",&b);
    for(i=a;i<=b;i++)
    {   oglindit=0;
        aux=i;
        while(aux!=0)
        {
            oglindit=oglindit*10+aux%10;
            aux/=10;
        }
        if(oglindit==i)
            fprintf(g,"%i ",i);
    }
    fclose(f);
    fclose(g);
    return 0;
}
