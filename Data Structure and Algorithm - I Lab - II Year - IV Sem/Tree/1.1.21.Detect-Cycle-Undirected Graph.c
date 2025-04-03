#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int parent, int vertex, int vertices, bool *hasCycle) {
    visited[vertex] = 1;
    
    for (int v = 0; v < vertices; v++) {
        if (graph[vertex][v]) {
            if (!visited[v]) {
                dfs(graph, visited, vertex, v, vertices, hasCycle);
            } else if (v != parent) {
                *hasCycle = true;
                return;
            }
        }
    }
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    bool hasCycle = false;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(graph, visited, -1, i, vertices, &hasCycle);
            if (hasCycle) {
                break;
            }
        }
    }

    if (hasCycle) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}

