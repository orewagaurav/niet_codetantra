#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX_VERTICES], rank[MAX_VERTICES];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_sets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot != yroot) {
        if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int main() {
    int vertices, edges;
    scanf("%d", &vertices);
    scanf("%d", &edges);

    Edge edge_list[edges];

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edge_list[i].u, &edge_list[i].v, &edge_list[i].weight);
    }

    qsort(edge_list, edges, sizeof(Edge), compare);

    int mst_weight = 0;
    int mst_edges = 0;

    for (int i = 0; i < edges; i++) {
        int u = edge_list[i].u;
        int v = edge_list[i].v;
        int weight = edge_list[i].weight;

        if (find(u) != find(v)) {
            printf("%d %d %d\n", u, v, weight);
            mst_weight += weight;
            union_sets(u, v);
            mst_edges++;
        }

        if (mst_edges == vertices - 1)
            break;
    }

    printf("%d\n", mst_weight);

    return 0;
}

