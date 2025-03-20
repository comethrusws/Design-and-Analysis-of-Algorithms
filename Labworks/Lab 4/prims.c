#include <stdio.h>
#include <time.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim(int n, int graph[MAX][MAX]) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    int mstWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        printf("Edge (%d, %d) with weight %d\n", parent[i], i, graph[i][parent[i]]);
        mstWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (%d x %d) (use 0 for no edge):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    clock_t start_time = clock();
    
    prim(n, graph);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}