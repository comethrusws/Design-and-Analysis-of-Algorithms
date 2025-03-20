#include <stdio.h>
#include <time.h>

#define MAX 20

int isSafe(int board[MAX][MAX], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    return 1;
}

int solveNQueensUtil(int board[MAX][MAX], int col, int n) {
    if (col >= n) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            
            if (solveNQueensUtil(board, col + 1, n)) {
                return 1;
            }
            
            board[i][col] = 0;
        }
    }
    
    return 0;
}

void solveNQueens(int n) {
    int board[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    if (solveNQueensUtil(board, 0, n)) {
        printf("Solution exists:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid value of N. Must be between 1 and %d.\n", MAX);
        return 1;
    }
    
    clock_t start_time = clock();
    
    solveNQueens(n);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}