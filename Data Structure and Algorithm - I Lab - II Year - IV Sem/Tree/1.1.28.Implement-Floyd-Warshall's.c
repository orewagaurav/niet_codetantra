#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void floydWarshall(int vertices, int graph[vertices][vertices]) {
    int dist[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = INF;
        }
    }

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
		int j;
        for (j = 0; j < vertices-1; j++) {
            if (dist[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
		printf("%d\n",dist[i][j]);
	}
}

int main() {
    int vertices, edges;

    scanf("%d", &vertices);
    scanf("%d", &edges);

    int graph[vertices][vertices];

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
    }

    floydWarshall(vertices, graph);

    return 0;
}

