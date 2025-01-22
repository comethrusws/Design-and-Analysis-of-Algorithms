#include <stdio.h>
#include <time.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    clock_t start_declare_time = clock();

    clock_t start_process_time = clock();

    int result = gcd(a, b);

    clock_t end_process_time = clock();

    printf("\nGCD of %d and %d is: %d\n", a, b, result);

    double declare_to_process_time = ((double)(start_process_time - start_declare_time)) / CLOCKS_PER_SEC * 1000;
    double process_duration = ((double)(end_process_time - start_process_time)) / CLOCKS_PER_SEC * 1000;
    double total_time = ((double)(end_process_time - start_declare_time)) / CLOCKS_PER_SEC * 1000;

    printf("\nTime taken from declaration to process start: %.6f ms\n", declare_to_process_time);
    printf("Time taken for the computation process: %.6f ms\n", process_duration);
    printf("Total time taken: %.6f ms\n", total_time);

    return 0;
}
