#include <stdio.h>
#include <time.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int n, int graph[MAX][MAX], int src) {
    int dist[MAX];
    int sptSet[MAX];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;
        
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: Unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (%d x %d) (use 0 for no edge):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    clock_t start_time = clock();
    
    dijkstra(n, graph, src);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}