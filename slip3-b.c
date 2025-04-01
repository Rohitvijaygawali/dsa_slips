//C program to implement graph traversal method using 
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix for the graph
int visited[MAX];  // Array to track visited vertices
int vertices;      // Total number of vertices

void DFS(int vertex) {
    printf("Visited vertex %d\n", vertex);
    visited[vertex] = 1;

    // Explore neighbors
    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}