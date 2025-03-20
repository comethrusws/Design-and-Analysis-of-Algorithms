#include <stdio.h>
#include <time.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void kruskal(int n, int edges[][3], int e) {
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                swap(&edges[j][0], &edges[j + 1][0]);
                swap(&edges[j][1], &edges[j + 1][1]);
                swap(&edges[j][2], &edges[j + 1][2]);
            }
        }
    }
    
    int mstWeight = 0;
    int mstEdges = 0;
    
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e && mstEdges < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        if (find(u) != find(v)) {
            unionSet(u, v);
            printf("Edge (%d, %d) with weight %d\n", u, v, weight);
            mstWeight += weight;
            mstEdges++;
        }
    }
    
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    int edges[e][3];
    printf("Enter %d edges (u v weight):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    
    clock_t start_time = clock();
    
    kruskal(n, edges, e);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}