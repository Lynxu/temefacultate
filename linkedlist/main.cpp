#include <stdio.h>
#include <malloc.h>

struct list
{
    int k;
    struct list *next;
};

int found(struct list *t, int val)
{
    while(1)
    {
	if(t==NULL)
	    return 0;
	if(t->k==val)
	    return 1;
	t=t->next;
    }
}

struct list *init_l(struct list *l)
{
    struct list *aux;
    char c, c1;
    int x;
    printf("Would you like to init the list? (y/n) ");
    scanf("%c",&c);
    c1=getchar();
    l=NULL;
    while ((c=='y'))
    {
        printf("Key's value: ");
        scanf("%i", &x);

        //if read key not found inside the list then add it to the list
        if(!found(l, x))
        {
            printf("%i not found inside the list. Gonna add it.\n", x);
            aux=(struct list *)malloc(sizeof(struct list));
            aux->k=x;
            aux->next=l;
            l=aux;
        }
        else
            printf("%i found inside the list. Gonna ignore it.\n", x);
        c1=getchar();
        printf("Add another key to list? (y/n) ");
        scanf("%c", &c);
        c1=getchar();
    }

    return(l);
}

void Display(struct list *l)
{
    struct list *p;
    for(p=l;p;p=p->next) printf("%d->",p->k);
    printf("NULL\n");
}

int main()
{
    struct list*l;

    l=init_l(l);
    printf("\n\nThe input linked list is :\n");
    Display(l);

    return 0;
}
