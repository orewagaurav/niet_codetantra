#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[vertices];
    int key[vertices];
    int mstSet[vertices];
    int totalCost = 0;

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < vertices; i++) {
        totalCost += graph[i][parent[i]];
    }

    return totalCost;
}

int main() {
    int vertices;
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int totalCost = primMST(graph, vertices);
    printf("%d\n", totalCost);

    return 0;
}

