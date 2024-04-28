#include<stdio.h>
#include<stdlib.h>

int nodeCount[20] = {0};

struct node{
    int data;
    struct node *left, *right;
};
typedef struct node N;

N* createNode(int data){
    N* newnode = (N*) malloc(sizeof(N));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

N* insertNode(N* root, int data){
    if(root == NULL)
        return createNode(data);
    if(root->data > data)
        root->left = insertNode(root->left, data);
    else if(root->data < data)
        root->right = insertNode(root->right, data);
    return root;
}

void countPrintNode(N*root, int level){
    if(root!=NULL){
        nodeCount[level]++;
        printf("Level %d: %d\n", level, root->data);
        countPrintNode(root->left, level+1);
        countPrintNode(root->right, level+1);
    }
}
