#include <stdio.h>
#include <time.h>

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void jobSequencing(int n, int profits[], int deadlines[], int ids[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profits[j] < profits[j + 1]) {
                swapInt(&profits[j], &profits[j + 1]);
                swapInt(&deadlines[j], &deadlines[j + 1]);
                swapInt(&ids[j], &ids[j + 1]);
            }
        }
    }
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }
    
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1;
    }
    
    int totalProfit = 0;
    int scheduled[n];
    for (int i = 0; i < n; i++) {
        scheduled[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = ids[i];
                scheduled[i] = 1;
                totalProfit += profits[i];
                break;
            }
        }
    }
    
    printf("Total profit: %d\n", totalProfit);
    printf("Scheduled jobs (Job ID - Profit):\n");
    for (int i = 0; i < n; i++) {
        if (scheduled[i] == 1) {
            printf("Job %d - %d\n", ids[i], profits[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    int profits[n], deadlines[n], ids[n];
    printf("Enter the profits of %d jobs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
    
    printf("Enter the deadlines of %d jobs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &deadlines[i]);
    }
    
    for (int i = 0; i < n; i++) {
        ids[i] = i + 1;
    }
    
    clock_t start_time = clock();
    
    jobSequencing(n, profits, deadlines, ids);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}