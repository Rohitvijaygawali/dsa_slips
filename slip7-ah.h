#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * cn(int data)
{
    struct node * nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}

struct node * insert(struct node * root ,int data)
{
    if(root==NULL)
    {
        return cn(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);

    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void display(struct node * root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d",root->data);
        display(root->right);
    }
}

void preorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
