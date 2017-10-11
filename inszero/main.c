#include <stdio.h>

void Read(int *n, float a[100], float *x)
{
    int i;
    printf("Input your array!\nn=");
    scanf("%i", n);
    for(i=0; i<*n; i++)
    {
        printf("a[%i]=", i);
        scanf("%f", &a[i]);
    }
    printf("After what number would you like to add a zero?\nx=");
    scanf("%f", x);
}

void AddZero(int *n, float a[100], int pos)
{
    int i;

    //move elements to the right
    for(i=*n; i>=pos+2; i--)
        a[i]=a[i-1];

    a[pos+1]=0;

    //update the length of the array
    (*n)++;
}

void Insert(int *n, float a[100], float x)
{
    int i, end;

    //n*2-1 iterations to be sure we parse all the array
    //posible input: all array elements could be equal with the x input value
    end=*n*2-1;

    i=0;
    while(i<end)
    {
        if(a[i]!=x)
            i++;
        else
        {
            //it will parse from i position to end of array
            AddZero(n, a, i);

            i=i+2;
        }
    }
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
    float x, a[100];
    Read(&n, a, &x);
    Insert(&n, a, x);
    printf("The new array: ");
    Print(n, a);
    return 0;
}
