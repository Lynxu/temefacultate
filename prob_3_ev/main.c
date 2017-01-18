#include <stdio.h>
#include <stdlib.h>

void read(int a[40], int n, int x)
{
    int i;
    scanf("%i", &n);
    for(i=0;i<n;i++)
    {
        printf("a[%i]=",i);
        scanf("%i", &a[i]);
        printf("Caracter citit!\n");
    }
    printf("\nx="); scanf("%i", &x);
    printf("A fost citit x");
}

/*
void write(float x)
{
    FILE *out;
    out=fopen("output.txt", "w+");
    fprintf(out, "%f", x);
    fclose(out);
}
*/

int control_digit(int x)
{
    while(x>9)
    {
        int sum=0;
        while(x!=0)
        {
            sum+=x%10;
            x/=10;
        }
        x=sum;
    }
    return x;
}

int main()
{

    int i, n, x, a[40];
    float S=0, nr=0;

    read(a, *n, *x);

    printf("%i", n);
    /*
    printf("%i", a[0]);
    printf("%i", a[1]);
    printf("%i", a[2]);
    */

    /*
    scanf("%i", &n);
    for(i=0;i<n;i++)
    {
        printf("a[%i]=",i);
        scanf("%i", &a[i]);
    }
    printf("\nx="); scanf("%i", &x);

    */

   // printf("\n");


/*

    for(i=0; i<n; i++)
        printf("%d", a[i]);


*/



  //  printf("\n");

    /*
    for(i=0; i<n; i++)
    {
        if(control_digit(a[i]) == x)
        {
            S+=a[i];
            nr++;
        }
    }

    printf("%f", S/nr);
    */

    //printf("%i", control_digit(917));

//    write(S/nr);
    return 0;
}

