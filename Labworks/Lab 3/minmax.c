#include <stdio.h>
#include <time.h>

void findMinMax(int arr[], int size, int *min, int *max) {
    int i;
    if (size % 2 == 0) {
        if (arr[0] > arr[1]) {
            *max = arr[0];
            *min = arr[1];
        } else {
            *max = arr[1];
            *min = arr[0];
        }
        i = 2;
    } else {
        *min = arr[0];
        *max = arr[0];
        i = 1;
    }
    
    while (i < size - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > *max) *max = arr[i];
            if (arr[i + 1] < *min) *min = arr[i + 1];
        } else {
            if (arr[i + 1] > *max) *max = arr[i + 1];
            if (arr[i] < *min) *min = arr[i];
        }
        i += 2;
    }
    
    if (size % 2 != 0 && arr[size - 1] > *max) *max = arr[size - 1];
    if (size % 2 != 0 && arr[size - 1] < *min) *min = arr[size - 1];
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min, max;
    clock_t start_time = clock();
    
    findMinMax(arr, n, &min, &max);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}