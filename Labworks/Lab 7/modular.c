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

int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, &x, &y);
    if (g != 1) {
        return -1;
    }
    return (x % m + m) % m;
}

void solveModularEquation(int a, int b, int m) {
    int g = extendedGCD(a, m, &(int){0}, &(int){0});
    
    if (b % g != 0) {
        printf("No solution exists.\n");
        return;
    }
    
    a /= g;
    b /= g;
    m /= g;
    
    int x0 = (b * modInverse(a, m)) % m;
    if (x0 < 0) x0 += m;
    
    printf("Solutions for x in %dx ≡ %d (mod %d):\n", a * g, b * g, m * g);
    for (int i = 0; i < g; i++) {
        int x = (x0 + i * m) % (m * g);
        printf("x ≡ %d (mod %d)\n", x, m * g);
    }
}

int main() {
    int a, b, m;
    printf("Enter a, b, and m (for ax ≡ b (mod m)): ");
    scanf("%d %d %d", &a, &b, &m);
    
    if (m <= 0) {
        printf("Modulus m must be positive.\n");
        return 1;
    }
    
    clock_t start_time = clock();
    
    solveModularEquation(a, b, m);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}