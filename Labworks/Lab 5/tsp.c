#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 8

int tsp(int** graph, int n, int pos, int visited, int** dp, int** parent) {
    if (visited == (1 << n) - 1) {
        return graph[pos][0];
    }
    
    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }
    
    int minCost = INT_MAX;
    int nextCity = -1;
    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i))) {
            int newVisited = visited | (1 << i);
            int cost = graph[pos][i] + tsp(graph, n, i, newVisited, dp, parent);
            if (cost < minCost) {
                minCost = cost;
                nextCity = i;
            }
        }
    }
    
    dp[pos][visited] = minCost;
    parent[pos][visited] = nextCity;
    return minCost;
}

void printPath(int** parent, int n) {
    int visited = 1;
    int pos = 0;
    int count = 0;
    printf("Tour: 0");
    
    while (count < n - 1) {
        int next = parent[pos][visited];
        if (next == -1) {
            printf("\nError: Unable to construct tour\n");
            return;
        }
        printf(" -> %d", next);
        visited |= (1 << next);
        pos = next;
        count++;
    }
    
    printf(" -> 0\n");
}

int main() {
    int n;
    printf("Enter the number of cities (max %d): ", MAX);
    scanf("%d", &n);
    
    if (n > MAX || n <= 1) {
        printf("Invalid number of cities. Must be between 2 and %d.\n", MAX);
        return 1;
    }
    
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
    }
    
    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int** dp = (int**)malloc(n * sizeof(int*));
    int** parent = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((1 << n) * sizeof(int));
        parent[i] = (int*)malloc((1 << n) * sizeof(int));
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
            parent[i][j] = -1;
        }
    }
    
    clock_t start_time = clock();
    
    int minCost = tsp(graph, n, 0, 1, dp, parent);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Minimum cost of the tour: %d\n", minCost);
    printPath(parent, n);
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    for (int i = 0; i < n; i++) {
        free(graph[i]);
        free(dp[i]);
        free(parent[i]);
    }
    free(graph);
    free(dp);
    free(parent);
    
    return 0;
}