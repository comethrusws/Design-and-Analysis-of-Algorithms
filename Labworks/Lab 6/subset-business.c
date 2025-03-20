#include <stdio.h>
#include <time.h>

#define MAX 100

int isSubsetSum(int set[], int n, int sum, int subset[], int index, int currSum) {
    if (currSum == sum) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++) {
            if (subset[i] == 1) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return 1;
    }
    
    if (index == n || currSum > sum) {
        return 0;
    }
    
    subset[index] = 1;
    if (isSubsetSum(set, n, sum, subset, index + 1, currSum + set[index])) {
        return 1;
    }
    
    subset[index] = 0;
    if (isSubsetSum(set, n, sum, subset, index + 1, currSum)) {
        return 1;
    }
    
    return 0;
}

int main() {
    int n, sum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int set[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    
    int subset[n];
    for (int i = 0; i < n; i++) {
        subset[i] = 0;
    }
    
    clock_t start_time = clock();
    
    if (!isSubsetSum(set, n, sum, subset, 0, 0)) {
        printf("No subset found with the given sum.\n");
    }
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}