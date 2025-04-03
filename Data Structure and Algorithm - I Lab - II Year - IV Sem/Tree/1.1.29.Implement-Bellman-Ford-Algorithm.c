#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void bellman_ford(int vertices, int edges, int graph[edges][3], int source) {
    int distance[vertices];
    
    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;
    
    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }
    
    for (int j = 0; j < edges; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("-1\n");
            return;
        }
    }
    
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF) {
            printf("%d INF\n", i);
        } else {
            printf("%d %d\n", i, distance[i]);
        }
    }
}

int main() {
    int vertices, edges;
    
    scanf("%d", &vertices);
    scanf("%d", &edges);
    
    int graph[edges][3];
    
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    
    int source;
    scanf("%d", &source);
    
    bellman_ford(vertices, edges, graph, source);
    
    return 0;
}

