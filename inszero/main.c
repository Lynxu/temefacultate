/*
The program reads from keyboard n array real distinct values and a x real value (array value).
It must insert after the x value of the array one value of zero.  */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Read(int *n, float a[100])
{
    int i;
    printf("n=");
    scanf("%i", n);
    for(i=0; i<*n; i++)
    {
        printf("a[%i]=", i);
        scanf("%f", &a[i]);
    }
}

void Insert(int *n, float a[100])
{
    int i, mem;
    float x;
    printf("x=");
    scanf("%f", &x);

    for(i=0; i<*n; i++)
        if(a[i]==x)
            mem=i; //position of x inside the array

    //move elements to right
    for(i=*n; i>=mem+2; i--)
        a[i]=a[i-1];

    //insert the zero
    a[mem+1]=0;
    (*n)++;
}

void Print(int n, float a[100])
{
    int i;
    for(i=0; i<n; i++)
        printf("%f ", a[i]);
}


int main()
{
    int n;
    float a[100];
    Read(&n, a);

    printf("The input array: ");
    Print(n, a);
    printf("\n");

    Insert(&n, a);

    printf("The new array: ");
    Print(n, a);

    return 0;
}
