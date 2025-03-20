#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long modPow(long long base, long long exp, long long modulus) {
    long long result = 1;
    base %= modulus;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int millerRabinTest(long long n, long long d) {
    long long a = 2 + rand() % (n - 4);
    long long x = modPow(a, d, n);
    
    if (x == 1 || x == n - 1) {
        return 1;
    }
    
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if (x == 1) {
            return 0;
        }
        if (x == n - 1) {
            return 1;
        }
    }
    
    return 0;
}

int isPrime(long long n, int k) {
    if (n <= 1 || n == 4) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    
    for (int i = 0; i < k; i++) {
        if (!millerRabinTest(n, d)) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    long long n;
    int k;
    printf("Enter the number to test for primality: ");
    scanf("%lld", &n);
    
    printf("Enter the number of iterations (e.g., 5 for high accuracy): ");
    scanf("%d", &k);
    
    if (k <= 0) {
        printf("Number of iterations must be positive.\n");
        return 1;
    }
    
    srand(time(NULL));
    
    clock_t start_time = clock();
    
    if (isPrime(n, k)) {
        printf("%lld is prime.\n", n);
    } else {
        printf("%lld is composite.\n", n);
    }
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}