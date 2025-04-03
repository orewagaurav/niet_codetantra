#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    dist[source] = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        
        visited[u] = 1;
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d INF\n", i);
        else
            printf("%d %d\n", i, dist[i]);
    }
}

int main() {
    int vertices, edges;
    scanf("%d", &vertices);
    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    
    int source;
    scanf("%d", &source);
    
    dijkstra(graph, vertices, source);
    
    return 0;
}

