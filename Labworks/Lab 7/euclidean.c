#include <stdio.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    clock_t start_time = clock();
    
    int result = gcd(a, b);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("GCD of %d and %d is: %d\n", a, b, result);
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}