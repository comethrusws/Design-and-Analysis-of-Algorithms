#include <stdio.h>
#include <time.h>

long long factorial_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial_recursive(n - 1);
}


int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number is undefined.\n");
        return 1;
    }

    clock_t start_recursive = clock();
    long long result_recursive = factorial_recursive(num);
    clock_t end_recursive = clock();
    double time_recursive = ((double)(end_recursive - start_recursive)) / CLOCKS_PER_SEC;


    printf("\nFactorial of %d (Recursive): %lld\n", num, result_recursive);
    printf("Time taken (Recursive): %f seconds\n", time_recursive);
    return 0;
}
