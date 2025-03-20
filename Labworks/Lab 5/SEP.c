#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 100

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void editDistance(char str1[], char str2[], int m, int n) {
    int dp[MAX][MAX];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    
    printf("Minimum operations to transform '%s' into '%s': %d\n", str1, str2, dp[m][n]);
}

int main() {
    char str1[MAX], str2[MAX];
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    clock_t start_time = clock();
    
    editDistance(str1, str2, m, n);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}