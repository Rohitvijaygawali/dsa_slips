/*Write a C program which uses Binary search tree library and implements following function with 
recursion: 
int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0 
otherwise.*/



#include <stdio.h>
#include <stdlib.h>
// craete the node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// traversal
struct Node* insert(struct Node* root, int value) {
    if (root==NULL) {
        return createNode(value);
    }
    if (value<root->data) {
        root->left=insert(root->left,value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
int identical(struct Node*root,struct Node*root1){ 
if(root==NULL && root1==NULL)
 { 
 return 1; 
 }
  if(root!=NULL && root1!=NULL) 
  {
   return (root->data==root1->data && identical(root->left,root1->left) && identical(root->right,root1->right));
   }
    return 0;
     }
int main() {
    struct Node*root=NULL;

    root=insert(root,5);
    insert(root,3);
    insert(root,4);
    insert(root,2);
    insert(root,9);
    insert(root,6);
    insert(root,8);
    struct Node*root1=NULL;

    root1=insert(root1,5);
    insert(root1,31);
    insert(root1,4);
    insert(root1,2);
    insert(root1,9);
    insert(root1,6);
    insert(root1,8);
if(identical(root,root1))
{
 printf("Trees are identical\n");
 }
 else 
 {
  printf("Trees are not identical\n"); 
  }
  
   return 0;

    
}

