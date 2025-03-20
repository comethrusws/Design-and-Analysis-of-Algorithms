#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];
    
    int pivotIndex = randomPartition(arr, low, high);
    
    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return quickSelect(arr, low, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, high, k);
}

int main() {
    srand(time(0));
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value of k (for k-th smallest element): ");
    scanf("%d", &k);
    k = k - 1;
    
    clock_t start_time = clock();
    
    int result = quickSelect(arr, 0, n - 1, k);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("The %d-th smallest element is: %d\n", k + 1, result);
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}