#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

// Function to print the path from source to target vertex
void printPath(int parent[], int v) {
    int path[1005];
    int count = 0;
    int curr = v;

    while (curr != -1) {
        path[count++] = curr;
        curr = parent[curr];
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
}

int main() {
    int V, E;
    if (scanf("%d", &V) != 1) return 0;
    if (scanf("%d", &E) != 1) return 0;

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int dist[1005];
    int parent[1005];

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Step 1: Relax all edges (V - 1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Step 2: Check for negative-weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    // Step 3: Print result
    if (hasNegativeCycle) {
        printf("Negative cycle detected\n");
    } else {
        for (int v = 1; v <= V; v++) {
            if (v == src) continue;

            if (dist[v] == INF) {
                printf("%d INF None\n", v);
            } else {
                printf("%d %d ", v, dist[v]);
                printPath(parent, v);
                printf("\n");
            }
        }
    }

    free(edges);
    return 0;
}
