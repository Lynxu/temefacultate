#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b; char x;
    printf("Introduceti primul numar: "); scanf("%i",&a);
    printf("Introduceti al doilea numar: "); scanf("%i",&b);
    getchar();
    printf("Introduceti operatia dorita +,-,*,/: ");
    scanf("%c",&x);
    switch(x)
    {
        case '+': printf("a+b=%i",a+b); break;
        case '-': printf("a-b=%i",a-b); break;
        case '*': printf("a*b=%i",a*b); break;
        case '/': printf("a/b=%f",a/(float)b); break;
        default : printf("Operatie inexistenta!");
    }
    return 0;
}
