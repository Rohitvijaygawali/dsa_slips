#include <stdio.h>
#include <stdlib.h>

void display(int adjMatrix[][100], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void calculateIndegree(int adjMatrix[][100], int vertices) {
    printf("\nIndegree of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        int indegree = 0;
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[j][i] == 1) {
                indegree++;
            }
        }
        printf("Vertex %d: %d\n", i, indegree);
    }
}

int main() {
    int vertices, edges;
    int adjMatrix[100][100] = {0}; // Initialize adjacency matrix with 0s

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        adjMatrix[start][end] = 1; // Directed edge from start to end
    }

    display(adjMatrix, vertices);
    calculateIndegree(adjMatrix, vertices);

    return 0;
}