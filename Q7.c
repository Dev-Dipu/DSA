// Write a C program for the implementation of Floyd Warshall’s algorithm for finding all pairs shortest path using adjacency cost matrix.

#include <stdio.h>
#include <stdlib.h>

#define max 9999

int min(int a, int b){
    return a < b ? a : b;
}

void warshall(int cost[][10], int v){
    int i, j, k;
    for(k = 0; k < v; k++)
        for(i = 0; i < v; i++)
            for(j = 0; j < v; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}


int main(){
    int cost[10][10];
    int i, j, v;

    printf("Enter no of vertices in graph: \n");
    scanf("%d",&v);

    printf("Enter cost matrix of graph: \n");
    for(i=0; i<v; i++)
        for(j=0; j<v; j++){
            scanf("%d", &cost[i][j]);
            if(!cost[i][j] && i!=j)
                cost[i][j] = max;
        }

    warshall(cost, v);

    printf("Shortest path between each pair of vertex is: \n");
    for(i=0; i<v; i++)
        for(j=0; j<v; j++)
            printf("%dV to %dV - %d\n", i, j, cost[i][j]);

}