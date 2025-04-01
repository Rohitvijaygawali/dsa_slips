/*C program to implement graph as adjacency matrix.  */


#include<stdio.h>
#include<stdlib.h>
 int adj[100][100]; // Adjacency matrix for the graph

 void main()
 {
    printf("Enter the number of vertices: ");
    int vertices;
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    int edges;  
    scanf("%d", &edges);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

 }