/*Write a C program that accepts the vertices and edges of a graph. Create adjacency 
display the adjacency list. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void addEdge(List* graph, int src, int dest) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->dest = dest;
    node->next = NULL;
    if (graph[src].head == NULL) {
        graph[src].head = node;
    } else {
        Node* curr = graph[src].head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void display(List* graph, int v) {
    for (int i = 0; i < v; i++) {
        printf("Vertex %d adjacency list: ", i);
        Node* curr = graph[i].head;
        while (curr != NULL) {
            printf("%d -> ", curr->dest);
            curr = curr->next;
        }
        printf("END\n");
    }
}

int main() {
    int v, e;
    printf("Number of vertices and edges: ");
    scanf("%d%d", &v, &e);
    List* graph = (List*)malloc(v * sizeof(List));
    for (int i = 0; i < v; i++) {
        graph[i].head = NULL;
    }

    for (int i = 0; i < e; i++) {
        int src, dest;
        printf("Edge %d (src dest): ", i + 1);
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }

    display(graph, v);
    for (int i = 0; i < v; i++) {
        Node* curr = graph[i].head;
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}

