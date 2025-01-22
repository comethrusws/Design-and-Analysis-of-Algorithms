#include <stdio.h>
#include <time.h>

long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int num;

    printf("Enter the Fibonacci term to calculate: ");
    scanf("%d", &num);

    clock_t start_recursive = clock();
    long long result_recursive = fibonacci_recursive(num);
    clock_t end_recursive = clock();
    double time_recursive = ((double)(end_recursive - start_recursive)) / CLOCKS_PER_SEC;

    printf("\nFibonacci term %d (Recursive): %lld\n", num, result_recursive);
    printf("Time taken (Recursive): %f seconds\n", time_recursive);

    return 0;
}
