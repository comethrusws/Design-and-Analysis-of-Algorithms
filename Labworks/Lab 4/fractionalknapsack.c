#include <stdio.h>
#include <time.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fractionalKnapsack(int n, int values[], int weights[], int capacity) {
    double ratio[n];
    int indices[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)values[i] / weights[i];
        indices[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(&ratio[j], &ratio[j + 1]);
                swapInt(&values[j], &values[j + 1]);
                swapInt(&weights[j], &weights[j + 1]);
                swapInt(&indices[j], &indices[j + 1]);
            }
        }
    }
    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    double selected[n];
    for (int i = 0; i < n; i++) {
        selected[i] = 0.0;
    }
    
    for (int i = 0; i < n; i++) {
        if (remainingCapacity >= weights[i]) {
            selected[indices[i]] = 1.0;
            totalValue += values[i];
            remainingCapacity -= weights[i];
        } else {
            selected[indices[i]] = (double)remainingCapacity / weights[i];
            totalValue += selected[indices[i]] * values[i];
            remainingCapacity = 0;
            break;
        }
    }
    
    printf("Maximum value in knapsack: %.2f\n", totalValue);
    printf("Items selected (fraction of each item):\n");
    for (int i = 0; i < n; i++) {
        if (selected[i] > 0.0) {
            printf("Item %d: %.2f (Value = %.2f, Weight = %.2f)\n", i + 1, selected[i], selected[i] * values[indices[i]], selected[i] * weights[indices[i]]);
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
    
    fractionalKnapsack(n, values, weights, capacity);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}