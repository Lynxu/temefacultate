#include <stdio.h>
#include <stdlib.h>

void Read(int *length, int *start, int *w) //we get the addresses
{
    scanf("%i", length); // scanf will put value at the address indicated by length
                            // length it's a pointer

    for(int i=0;i<(*length);i++)
        scanf("%i", start++);
    scanf("%i", w);
}

void Write(float x)
{
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "%f", x), fclose(out);
}


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

    int i, n, x, A[40];
    float S=0, nr=0;

    Read(&n, A, &x); //we send addresses
                     //A it's the address of the first array element (A = &A[0] = &A)
                     //Elements of the array are memorized into a continous block memory,
                     //each address being one after the other

    for(i=0; i<n; i++)
        if(control_digit(A[i]) == x)
            S+=A[i], nr++;

    Write(S/nr);

    return 0;
}

