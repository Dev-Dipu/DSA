// Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix

#include<stdio.h>
#define max_vertices 20
int Matrix[max_vertices][max_vertices] = {0};

void addEdge(int v1, int v2){
    Matrix[v1][v2] = 1;
    Matrix[v2][v1] = 1;
}

void displayMatrix(int vertices){
    int i, j;
    for(i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            printf("%2d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vertices, edges, i;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &vertices);
    printf("\nEnter the number of edges: ");
    scanf("%d", &edges);

    printf("\nEnter the path:");
    for(i = 0; i < edges; i++){
        int v1, v2;
        printf("\nEdge %d:", i+1);
        scanf("%d %d", &v1, &v2);
        addEdge(v1-1, v2-1);
    }

    displayMatrix(vertices);

}