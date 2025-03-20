#include <stdio.h>
#include <time.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int values[], int weights[], int capacity, int index, int currValue, int currWeight, int selected[], int* maxValue, int bestSelected[]) {
    if (currWeight <= capacity) {
        if (currValue > *maxValue) {
            *maxValue = currValue;
            for (int i = 0; i < n; i++) {
                bestSelected[i] = selected[i];
            }
        }
    }
    
    if (index == n || currWeight > capacity) {
        return;
    }
    
    selected[index] = 1;
    knapsack(n, values, weights, capacity, index + 1, currValue + values[index], currWeight + weights[index], selected, maxValue, bestSelected);
    
    selected[index] = 0;
    knapsack(n, values, weights, capacity, index + 1, currValue, currWeight, selected, maxValue, bestSelected);
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
    
    int selected[n], bestSelected[n];
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
        bestSelected[i] = 0;
    }
    
    int maxValue = 0;
    
    clock_t start_time = clock();
    
    knapsack(n, values, weights, capacity, 0, 0, 0, selected, &maxValue, bestSelected);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Maximum value in knapsack: %d\n", maxValue);
    printf("Selected items (Item ID - Value - Weight):\n");
    for (int i = 0; i < n; i++) {
        if (bestSelected[i]) {
            printf("Item %d - %d - %d\n", i + 1, values[i], weights[i]);
        }
    }
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}