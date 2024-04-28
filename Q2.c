// Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, preorder. Write a menu driven program that performs the above operations.

#include "btree.h"

int main(){
    N*root = NULL;
    int ch, data;

    printf("1. insert\n");
    printf("2. preorder\n");
    printf("3. exit\n");

    

    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                printf("Exit...");
        }
    }while(ch!=3);
}