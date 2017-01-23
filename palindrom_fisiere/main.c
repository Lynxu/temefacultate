#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,aux,oglindit=0;
    FILE *f=fopen("numar.txt","r");
    fscanf(f,"%i",&n);
    aux=n;
    while(aux)
    {
        oglindit=oglindit*10+aux%10;
        aux/=10;
    }
    if(n==oglindit)
        printf("Numarul este palindrom!");
        else
        printf("Numarul nu este palindrom!");
    return 0;
}
