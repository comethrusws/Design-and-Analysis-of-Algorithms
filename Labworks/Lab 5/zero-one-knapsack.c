#include <stdio.h>
#include <time.h>

#define MAX 100

void knapsack(int n, int values[], int weights[], int capacity) {
    int dp[MAX][MAX];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w) {
                if (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) {
                    dp[i][w] = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                }
                else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    int selected[n];
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }
    
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[i - 1] = 1;
            w -= weights[i - 1];
        }
    }
    
    printf("Maximum value in knapsack: %d\n", dp[n][capacity]);
    printf("Selected items (Item ID - Value - Weight):\n");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Item %d - %d - %d\n", i + 1, values[i], weights[i]);
        }
    }
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int values[n], weights[n];
    printf("Enter the values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Enter the weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    
    clock_t start_time = clock();
    
    knapsack(n, values, weights, capacity);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}