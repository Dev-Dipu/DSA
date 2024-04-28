// Write a C program which uses Binary search tree library and displays nodes at each level,count of node at each level.
#include "bstlibrary.h"

int main(){
    N* root = NULL;
    int i = 0;

    root = insertNode(root, 8);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 5);

    printf("Nodes at each level:\n");
    countPrintNode(root, 0);
    printf("Count of node at each level:\n");
    while(nodeCount[i]!=0){
        printf("level %d: %d\n", i, nodeCount[i]);
        i++;
    }
        
}