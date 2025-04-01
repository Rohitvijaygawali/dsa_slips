/*Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement function to traverse the graph using Breadth First Search (BFS) traversal. [15]*/


#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

void bfs_traversal(int start_vertex, int num_vertices) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = start_vertex;
    visited[start_vertex] = 1;
    printf("Breadth-First Search Order: ");
    while (front < rear) {
        int current_vertex = queue[front++];
        printf("Node %d ", current_vertex);
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[current_vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int num_vertices, num_edges, u, v;
    printf("Vertices Count: ");
    scanf("%d", &num_vertices);
    printf("Edges Count: ");
    scanf("%d", &num_edges);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Input Edges (u v):\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int start_vertex;
    printf("Starting Vertex: ");
    scanf("%d", &start_vertex);

    bfs_traversal(start_vertex, num_vertices);

    return 0;
}

