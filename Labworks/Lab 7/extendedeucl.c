#include <stdio.h>
#include <time.h>

int extendedGCD(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    int x, y;
    int originalA = a, originalB = b;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    clock_t start_time = clock();
    
    int gcd = extendedGCD(a, b, &x, &y);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("GCD of %d and %d is: %d\n", originalA, originalB, gcd);
    printf("Coefficients x and y: %d and %d\n", x, y);
    printf("Verification: %d * %d + %d * %d = %d\n", originalA, x, originalB, y, originalA * x + originalB * y);
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}