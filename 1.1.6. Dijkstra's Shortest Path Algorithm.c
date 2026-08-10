#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
int distance[MAX], pred[MAX], visited[MAX];
    int i, j, count, mindistance, nextnode;

    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;

    for (count = 1; count <= n - 1; count++) {
        mindistance = INFINITY;
        nextnode = -1;

        for (i = 1; i <= n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        if (nextnode == -1) break;

        visited[nextnode] = 1;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && G[nextnode][i] != 0) {
                if (mindistance + G[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + G[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
    }

    printf("Node\tDistance\tPath\n");
    for (i = 1; i <= n; i++) {
        if (i == startnode) continue;

        if (distance[i] >= INFINITY) {
            printf("%4d\t%8s\tNO PATH\n", i, "INF");
        } else {
            printf("%4d\t%8d\t", i, distance[i]);

            int curr = i;
            while (curr != startnode) {
                printf("%d<-", curr);
                curr = pred[curr];
            }
            printf("%d\n", startnode);
        }
	}
	
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
