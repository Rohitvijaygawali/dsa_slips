/* C program to implement BST to perform the following operations on BST:
   a) Create
   b) Counting leaf nodes.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* cn(int data) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return cn(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void display(struct node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// Count the number of leaf nodes in the BST
unsigned int getLeafNodeCount(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
}

int main() {
    struct node* root = NULL;
    int ch, data;
    printf("1. Insert\n2. Display\n3. Leaf count\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                display(root);
                printf("\n");
                break;
            case 3: {
                int leafNodes = getLeafNodeCount(root);
                printf("Total number of leaf nodes: %d\n", leafNodes);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}