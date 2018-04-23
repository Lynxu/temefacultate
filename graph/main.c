#include <stdio.h>
#include <stdlib.h>

struct adjvertexlist
{
    int index_vertex;
    struct adjvertexlist *next;
};

struct vertexlist
{
    int index_vertex;
    struct vertexlist *next;
    struct adjvertexlist *list;
};


struct graphrep
{
    int nv;
    int ne;
    struct vertexlist *head;
};

typedef struct graphrep graph;

int VertexAdded(graph *g, int v)
{
    struct vertexlist *iterat_vlist;
    iterat_vlist = g->head;

    while(iterat_vlist)
    {
        if(iterat_vlist->index_vertex == v)
        {
            printf("Vertex %i found inside graph\n", v);
            return 1;

        }
        iterat_vlist = iterat_vlist->next;
    }
    
    printf("Vertex %i not found inside graph\n", v);
    return 0;
}

graph* AddVertex(graph *g, int v)
{
    struct vertexlist *new_vcell;
    new_vcell = malloc(sizeof(struct vertexlist));
    new_vcell->next = g->head;
    g->head = new_vcell;
    new_vcell->index_vertex = v;
    new_vcell->list = NULL;
    printf("Added %i vertex on graph\n", v);
    return g;
}

graph* AddEdge(graph *g, int v1, int v2)
{
    printf("\nAddEdge() started\n");
    printf("Edge to add from %i to %i and from %i to %i\n", v1, v2, v2, v1);
    struct adjvertexlist *new_adjvcell;
    struct vertexlist *iterat_vlist;
    iterat_vlist = g->head;
    while(iterat_vlist)
    {
        if(iterat_vlist->index_vertex == v1)
        {
            new_adjvcell = malloc(sizeof(struct adjvertexlist));
            new_adjvcell->index_vertex = v2;
            new_adjvcell->next = iterat_vlist->list;
            iterat_vlist->list = new_adjvcell;
            printf("Added edge from %i to %i\n", iterat_vlist->index_vertex, v2);
        }
        if(iterat_vlist->index_vertex == v2)
        {
            new_adjvcell = malloc(sizeof(struct adjvertexlist));
            new_adjvcell->index_vertex = v1;
            new_adjvcell->next = iterat_vlist->list;
            iterat_vlist->list = new_adjvcell;
            printf("Added edge from %i to %i\n", iterat_vlist->index_vertex, v1);
        }
        iterat_vlist = iterat_vlist->next;
    }
    printf("AddEdge() finished\n\n");
    return g;
}

graph* ReadGraph(graph *g, FILE *f)
{
    int i, x, y;
    fscanf(f, "%i %i", &g->nv, &g->ne);
    printf("Number of vertices read: %i\n", g->nv);
    printf("Number of edges read: %i\n", g->ne);
    for(i=1; i<=g->nv; i++)
    {
        fscanf(f, "%i", &x);
        g = AddVertex(g, x);
    }
    for(i=1; i<=g->ne; i++)
    {
        fscanf(f, "%i %i", &x, &y);
        printf("Edge read: %i, %i\n", x, y);
        g = AddEdge(g, x, y);
    }
    fclose(f);
    return g;
}

void ShowGraph(graph *g)
{
    struct vertexlist *iterat_vlist;
    struct adjvertexlist *iterat_adjvlist;
    iterat_vlist = g->head;
    while(iterat_vlist)
    {
        printf("%i -> : ", iterat_vlist->index_vertex);
     
        iterat_adjvlist = iterat_vlist->list;
        while(iterat_adjvlist)
        {
            printf("T%i ", iterat_adjvlist->index_vertex);
            iterat_adjvlist = iterat_adjvlist->next;
        }
        printf("\n");
     
        iterat_vlist = iterat_vlist->next;
    }

}

int EdgeFound(graph *g, int v1, int v2)
{
    struct vertexlist *iterat_vlist;
    struct adjvertexlist *iterat_adjvlist;
    iterat_vlist = g->head;
    while(iterat_vlist)
    {
        if(iterat_vlist->index_vertex == v1)
        {
            iterat_adjvlist = iterat_vlist->list;
            while(iterat_adjvlist)
            {
                if(iterat_adjvlist->index_vertex == v2)
                {
                    printf("Edge from %i to %i exists\n", iterat_vlist->index_vertex, iterat_adjvlist->index_vertex);    
                    return 1;
                }
                iterat_adjvlist = iterat_adjvlist->next;
            }
        }
        iterat_vlist = iterat_vlist->next;
    }
    printf("Edge from %i to %i doesn\'t exist\n", v1, v2);    
    return 0;
}

graph* MakeReunion(graph *r, graph *g1, graph *g2)
{
    printf("FFFFF");
    struct vertexlist *iterat_vlist;
    struct adjvertexlist *iterat_adjvlist;
    
    printf("First graph adding\n");
    //add vertices of first graph
    iterat_vlist = g1->head;
    while(iterat_vlist)
    {
        if(!VertexAdded(r, iterat_vlist->index_vertex))
            r = AddVertex(r, iterat_vlist->index_vertex);
        iterat_vlist = iterat_vlist->next;
     } 
    
    //add edges of first graph
    iterat_vlist = g1->head;
    while(iterat_vlist)
    {
        iterat_adjvlist = iterat_vlist->list;
        while(iterat_adjvlist)
        {
            if(!EdgeFound(r, iterat_vlist->index_vertex,
                          iterat_adjvlist->index_vertex))
                r = AddEdge(r, iterat_vlist->index_vertex,
                            iterat_adjvlist->index_vertex);
            iterat_adjvlist = iterat_adjvlist->next;
        }
        iterat_vlist = iterat_vlist->next;
    }
    

    printf("Second graph adding\n");
    //add vertices of second graph
    iterat_vlist = g2->head;
    while(iterat_vlist)
    {
        if(!VertexAdded(r, iterat_vlist->index_vertex))
            r = AddVertex(r, iterat_vlist->index_vertex);
        iterat_vlist = iterat_vlist->next;
     } 
    
    //add edges of first graph
    iterat_vlist = g2->head;
    while(iterat_vlist)
    {
        iterat_adjvlist = iterat_vlist->list;
        while(iterat_adjvlist)
        {
            if(!EdgeFound(r, iterat_vlist->index_vertex,
                          iterat_adjvlist->index_vertex))
                r = AddEdge(r, iterat_vlist->index_vertex,
                            iterat_adjvlist->index_vertex);
            iterat_adjvlist = iterat_adjvlist->next;
        }
        iterat_vlist = iterat_vlist->next;
    }
    return r;
}

int main()
{
    graph *g1, *g2, *rg;
    FILE *f1, *f2;
    g1 = malloc(sizeof(graph));
    g1->head = NULL;
    g2 = malloc(sizeof(graph));
    g2->head = NULL;
    f1 = fopen("graph1.txt", "r");
    f2 = fopen("graph2.txt", "r");
    g1 = ReadGraph(g1, f1);
    printf("Graful 1\n");
    ShowGraph(g1);
    printf("\n");
    g2 = ReadGraph(g2, f2);
    printf("Graful 2\n");
    ShowGraph(g2);
    
    
    rg = malloc(sizeof(graph));
    rg->head = NULL;
    rg = MakeReunion(rg, g1, g2);
    printf("Graful reuniune\n");
    ShowGraph(rg);
    

    return 0;
}
