#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,s=0,p=1,x;
    FILE *f;
    scanf("%i",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%i",&x);
        if(x>0)
        {
            p*=x;
            s+=x;
        }
    }
    f=fopen("calcule.txt","w+");
    fprintf(f,"p=%i\n",p);
    fprintf(f,"s=%i",s);
    fclose(f);
    return 0;
}
