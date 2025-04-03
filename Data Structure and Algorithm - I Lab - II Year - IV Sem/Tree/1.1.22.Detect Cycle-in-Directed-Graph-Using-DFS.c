#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int recStack[MAX_VERTICES], int vertex, int vertices) {
    visited[vertex] = 1;
    recStack[vertex] = 1;
    
    for (int v = 0; v < vertices; v++) {
        if (graph[vertex][v]) {
            if (!visited[v] && dfs(graph, visited, recStack, v, vertices)) {
                return true;
            } else if (recStack[v]) {
                return true;
            }
        }
    }

    recStack[vertex] = 0;
    return false;
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    int recStack[MAX_VERTICES] = {0};

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    bool hasCycle = false;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, recStack, i, vertices)) {
                hasCycle = true;
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

