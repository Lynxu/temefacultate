//immplementarea uniui graf cu lista de liste de adiacenta
#include <stdio.h>
#include <malloc.h>

struct AdjListCell
{
	int index_node;
	struct AdjListCell* next;
};
struct AdjList
{
	struct AdjListCell *head;
};
struct NodeListCell
{
	int index_node;
	struct NodeListCell *next;
	struct AdjList *list;
};
struct NodeList
{
	struct NodeListCell *head;
};
struct GraphRep
{
	int nV;//numarul de noduri
	int nE;//numarul de muchii
	struct NodeList *Glist;//lista nodurilor grafului
};
typedef struct GraphRep Graph;

/*functia de creare a unei celule pentru un nod al
grafului in lista nodurilor grafului*/
struct NodeListCell* newNodeListCell(int index_node)
{
	struct NodeListCell* newNode =
			(struct NodeListCell*) malloc(sizeof(struct NodeListCell));
	newNode->index_node = index_node;
	newNode->next = NULL;
	newNode->list=NULL;
	return newNode;
}
/*functia de constructie a unui graf*/
Graph* createGraph()
{
	Graph* g = (Graph*) malloc(sizeof(Graph));
	g->nV = 0;
	g->nE=0;
	g->Glist= (struct NodeList*) malloc (sizeof(struct NodeList));
	g->Glist->head=NULL;
	return g;
}
/*functia de adaugare a unui nod in graf*/
Graph* addNode(Graph* g, int v)
{
	g->nV++;
	struct NodeListCell *newNode=newNodeListCell(v);
	newNode->next=g->Glist->head;
	newNode->list=NULL;
	g->Glist->head=newNode;
	return g;
}

int NodeAdded(Graph* g, int v)
{
    struct NodeListCell *nlist;
    nlist = g->Glist->head;
    if(nlist)
	while(nlist)
	{
	    if(nlist->index_node == v)
		return 1;
	    nlist = nlist -> next;
	}
    return 0;
}


/*functia de creare a unei celule in lista de adiacenta asociata
nodului unui graf*/
struct AdjListCell* newAdjListCell(int index_node)
{
	struct AdjListCell* newCell =
			(struct AdjListCell*) malloc(sizeof(struct AdjListCell));
	newCell->index_node = index_node;
	newCell->next = NULL;
	return newCell;
}

Graph* addEdge(Graph* g, int v, int w)
{
    g->nE++;

    //we start from the last added vertex
    //nlist = address of last added vertex
    struct NodeListCell* nlist=g->Glist->head;

    //we loop each vertex data structure
    //from last to the first
    while (nlist)
    {
        //edge will be added, from v vertex to w vertex
	if (nlist->index_node==v)
	{
            //allocate memory for the w node data structure
            //w node it's part of v's vertex list of edges
	    struct AdjListCell* newCell = newAdjListCell(w);
	    newCell->next = (struct AdjListCell*)nlist->list;
	    nlist->list = (struct AdjList*)newCell;

	}
	//edge will be added, from w vertex to v vertex
	if (nlist->index_node==w)
	{
	    //we allocate memory for the v node data structure
            //v node it's part of w's vertex list of edges
	    struct AdjListCell* newCell = newAdjListCell(v);
	    newCell->next = (struct AdjListCell*)nlist->list;
	    nlist->list = (struct AdjList*)newCell;
	}
	nlist=nlist->next;
    }
    return g;
}

void showGraph(Graph* g)
{
	struct NodeListCell* nlist=g->Glist->head;
	while (nlist)
    {
        struct AdjListCell* plist;
        plist = (struct AdjListCell*)nlist->list;
		printf("Lista de adiacenta a nodului %d este:",nlist->index_node);
		if(plist)
		while (plist)
		{
			printf("-> %d",plist->index_node);
			plist = plist->next;
		}
		else
        {
            printf("-> *");
        }
        printf("\n");
        nlist=nlist->next;
    }
}

//1 if there's edge in graph g from vertex1 to vertex2
//0 otherwise
int EdgeFound(Graph* g, int vertex1, int vertex2)
{
    struct NodeListCell* nlist;
    struct AdjListCell* plist;
    
    //there is edge from one vertex to same vertex 
    if(vertex1 == vertex2)
        return 1;

    nlist = g->Glist->head;
    while(nlist)
    {
        if(nlist->index_node == vertex1)
        {
            plist = (struct AdjListCell*)nlist->list;
            if(plist)
		while(plist)
		{
		    if(plist->index_node == vertex2)
			return 1;
		    plist = plist->next;
		}
        }
	nlist = nlist->next;
    }
    return 0;
}

Graph* CopyGraph(Graph* s, Graph* d)
{
    struct NodeListCell* nlist;


    nlist = d->Glist->head;

    //for each vertex
    while(nlist)
    {
        struct AdjListCell* plist;
        plist = (struct AdjListCell*)nlist->list;

        //if vertex has edges
        if(plist)
	    while(plist)
	    {
                //if the source graph s doesn't contain the edge
                if(!EdgeFound(s, nlist->index_node, plist->index_node))
		    s = addEdge(s, nlist->index_node, plist->index_node);
		plist = plist->next;
	    }
        nlist=nlist->next;
    }
    printf("\n");
    return s;
}


Graph* GraphsReun(Graph* graph1,
                             Graph* graph2)
{
    int i;
    Graph* newgraph;

    newgraph = createGraph();

    //we append the biggest graph and after we
    //append the smallest
    if(graph1->nV > graph2->nV)
    {
        for(i=1; i<=graph1->nV; i++)
            newgraph = addNode(newgraph, i);
	newgraph = CopyGraph(newgraph, graph1);
	newgraph = CopyGraph(newgraph, graph2);
    }
    else
    {
        for(i=1; i<=graph2->nV; i++)
            newgraph = addNode(newgraph, i);
	newgraph = CopyGraph(newgraph, graph2);
	newgraph = CopyGraph(newgraph, graph1);
    }
    return newgraph;

}


Graph* readGraph(Graph* g, FILE *f)
{
    int i, n, m, x, y;
    fscanf(f,"%d%d",&n,&m);
    printf("Numarul de noduri este %d\n",n);
    printf("Numarul de muchii este %d\n",m);
    for(i=1;i<=m;i++)
    {
        fscanf(f,"%d%d",&x,&y);
        if(!NodeAdded(g, x))
            g = addNode(g, x);
        if(!NodeAdded(g, y))
            g = addNode(g, y);
        printf("Muchia %d %d\n", x, y);
        g=addEdge(g,x,y);
    }
    fclose(f);
    return g;
}

Graph* createComplementGraph(Graph* g, Graph *c)
{
    struct NodeListCell *vlist, *vlist2;
    vlist = g->Glist->head;

    if(vlist)
    //we copy each node from the provided graph 
    //to the complement graph
    while(vlist)
    {
	c = addNode(c, vlist->index_node);
	vlist = vlist->next;
    }
    else
    {
	printf("Error. The graph whose complement you would like to compute it's null!");
	return NULL;
    }
    
    vlist = g->Glist->head;
    //for each vertex data structure
    while(vlist)
    {
        vlist2 = g->Glist->head;
        while(vlist2) 
        {
	    if(vlist->index_node != vlist2->index_node)
		if(!EdgeFound(g, vlist->index_node, vlist2->index_node) &&
                   !EdgeFound(c, vlist->index_node, vlist2->index_node))
		    c = addEdge(c, vlist->index_node, vlist2->index_node);
            vlist2 = vlist2->next;
        }
        vlist = vlist->next;
    } 
    return c;
}

int main()
{
    FILE *f;
    Graph *my_graph, *complement_graph;

    f = fopen("graph.in", "r");
    my_graph = createGraph();
    my_graph = readGraph(my_graph, f);
    showGraph(my_graph);
    printf("\n");
    complement_graph = createGraph();
    complement_graph = createComplementGraph(my_graph, complement_graph);
    showGraph(complement_graph);
    return 0;
}

