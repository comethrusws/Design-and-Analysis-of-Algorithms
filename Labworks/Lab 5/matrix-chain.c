#include <stdio.h>
#include <time.h>
#include <limits.h>

#define MAX 100

void matrixChainMultiplication(int p[], int n) {
    int m[MAX][MAX];
    int s[MAX][MAX];
    
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    printf("Minimum number of multiplications: %d\n", m[1][n]);
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];
    printf("Enter the dimensions of %d matrices (p0, p1, ..., pn):\n", n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    clock_t start_time = clock();
    
    matrixChainMultiplication(p, n);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}