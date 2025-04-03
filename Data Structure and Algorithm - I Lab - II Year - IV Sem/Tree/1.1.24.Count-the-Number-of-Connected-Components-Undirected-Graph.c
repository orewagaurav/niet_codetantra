#include <stdio.h>

#define MAX_VERTICES 100

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertex, int vertices) {
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(graph, visited, i, vertices);
        }
    }
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    int connectedComponents = 0;

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, vertices);
            connectedComponents++;
        }
    }

    printf("%d\n", connectedComponents);

    return 0;
}


