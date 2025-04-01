/*Implement a Binary search tree (BST) library (btree.h) with operations – create, preorder and 
postorder. Write a menu driven program that performs the above operations.*/


#include <stdio.h>  
#include <stdlib.h>
#include "slip6-ah.h"
struct node * cn(int data);
struct node * insert(struct node * root ,int data);
void display(struct node * root);
void postorder(struct node * root);
void preorder(struct node * root);

void main()
{
  struct node *root=NULL;
    int ch,data;
    printf("1. Insert\n2. Display\n3. Preorder\n4. postorder\n5. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                display(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                printf("postorder traversal: ");
                postorder(root);
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}