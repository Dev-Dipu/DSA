// Write a program which uses binary search tree library and counts the total nodes and total leaf nodes in the tree. int count Leaf(T) – returns the total number of leaf nodes from BST

#include<stdio.h>
#include<stdlib.h>

int totalNode = 0;
int leafNode = 0;

struct node
{
    int data;
    struct node *left,*right;
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
    if(root==NULL)
        return createNode(data);
    if(root->data > data)
        root->left = insertNode(root->left, data);
    else if(root->data < data)
        root->right = insertNode(root->right, data);
    return root;
}

void inorder(N* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%2d", root->data);
        inorder(root->right);
    }
}

void countNode(N* root){
    if(root!=NULL){
        totalNode++;
        if(root->left == NULL && root->right == NULL)
            leafNode++;
        countNode(root->left);
        countNode(root->right);
    }
}



int main(){
    N* root = NULL;
    root = insertNode(root, 8);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 5);

    inorder(root);
    printf("\n");
    countNode(root);
        
    printf("total Nodes %d", totalNode);
    printf("leaf Nodes %d", leafNode);
}