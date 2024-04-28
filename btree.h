#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node N;

N* createNode(int data){
    N* newNode = (N*) malloc(sizeof(N));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

N* insert(N* root, int data){
    if(root == NULL)
        return createNode(data);
    if(root->data > data)
        root->left = insert(root->left, data);
    else if(root->data < data)
        root->right = insert(root->right, data);
    return root;
}

void preorder(N* root){
    if(root!=NULL){
        printf("%2d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}