// Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the adjacency list.

#include <stdio.h>
#include <stdlib.h>
#define max 20

struct node
{
    int vertex;
    struct node *next;
};
typedef struct node N;

N *createNode(int v)
{
    N *newnode = (N *)malloc(sizeof(N));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

void addEdge(N *adjlist[], int src, int dest)
{
    N *newnode = createNode(dest);
    newnode->next = adjlist[src];
    adjlist[src] = newnode;

    newnode = createNode(src);
    newnode->next = adjlist[dest];
    adjlist[dest] = newnode;
}

void printGraph(N *adjlist[], int v)
{
    for (int i = 1; i <= v; i++)
    {
        N *temp = adjlist[i];
        printf("list of vertex %d:", i);
        while (temp)
        {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main()
{
    int v, e;
    N *adjlist[max] = {NULL};
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int src, dest;
    printf("Enter the src and dest of edges: \n");
    for (int i = 0; i < e; i++)
    {
        printf("Edge %d:", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(adjlist, src, dest);
    }

    printf("Adjlist of graph:\n");
    printGraph(adjlist, v);
}
