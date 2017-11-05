/*The program reads a singly linked list.
It will move all the nodes containing prime numbers to a stack
(the linked list memory must be deallocated).
Compiler: gcc (GCC) 7.2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct list
{
    int key;
    struct list *next;
};

struct list* buildList()
{
    struct list *t, *aux;
    char s[100];
    printf("Would you like to init the singly linked list? (y/n) ");
    t=NULL;
    scanf("%s", s);
    if(!strcmp("y", s))
    {
        printf("The singly linked list will be built now using your input keys!\n");
        printf("Press s character to stop!\n");
        while(1)
        {
            printf("Input key value: ");
            scanf("%s", s);
            if(!strcmp("s", s))
                break;
            aux=(struct list *)malloc(sizeof(struct list));
            aux->key=atoi(s);
            aux->next=t;
            t=aux;
        }
    }
    return t;
};

void showList(struct list *m)
{
    struct list *it;
    for(it=m; it; it=it->next)
        printf("%i ", it->key);
}

int ItIsPrime(int x)
{
    int i;
    for(i=2; i<=x/2; i++)
        if(x%i==0)
            return 0;
    return 1;
}


void Push(struct list* &stck, int value)
{
    struct list *node;
    if(!stck)
    {
        stck=(struct list*)malloc(sizeof(struct list));
        stck->key=value;
        stck->next=NULL;
    }
    else
    {
        node=(struct list*)malloc(sizeof(struct list));
        node->key=value;
        node->next=stck;
        stck=node;
    }
}

void movePrimes(struct list *l, struct list * &stck)
{
    struct list *it;
    for(it=l; it; it=it->next)
    {
        if(ItIsPrime(it->key))
            Push(stck, it->key), printf("prime number: %i\n", it->key);
        free(it);
    }
}

int main()
{
    struct list *l, *stck;
    stck=NULL;
    l=buildList();
    showList(l);
    movePrimes(l, stck);

    printf("stack: ");
    showList(stck);
    return 0;
}
