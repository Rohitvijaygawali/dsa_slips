#include<stdio.h>
#include<stdlib.h>
#include"slip1-ah.h"

// function to be used
struct node *cn(int data);
struct node*insert(struct node*root,int data);
void display(struct node*root);

void main()
{
    struct node *root=NULL;
    int n;
    int data;
   while(1)
   {
    printf("Enter the choise\n1 insert\n 2.display\n3.exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :
        printf("Enter the data to be inserted\n");
        scanf("%d",&data);
        root=insert(root,data);
        break;

        case 2:
        printf("Enter tree is :\t");
        display(root);
        break;
        case 3:
        printf("exit\n");
        exit(0);
        default:
        printf("invalid choice\n");
        break;
    }
    }
}