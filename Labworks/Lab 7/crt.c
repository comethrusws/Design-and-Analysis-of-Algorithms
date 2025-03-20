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

int chineseRemainder(int a[], int m[], int k) {
    int M = 1;
    for (int i = 0; i < k; i++) {
        M *= m[i];
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (extendedGCD(m[i], m[j], &(int){0}, &(int){0}) != 1) {
                return -1;
            }
        }
    }
    
    int x = 0;
    for (int i = 0; i < k; i++) {
        int Mi = M / m[i];
        int inv = modInverse(Mi, m[i]);
        if (inv == -1) {
            return -1;
        }
        x += a[i] * Mi * inv;
    }
    
    return x % M;
}

int main() {
    int k;
    printf("Enter the number of congruences: ");
    scanf("%d", &k);
    
    int a[k], m[k];
    printf("Enter %d remainders (a1, a2, ..., ak):\n", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter %d moduli (m1, m2, ..., mk):\n", k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &m[i]);
        if (m[i] <= 0) {
            printf("Moduli must be positive.\n");
            return 1;
        }
    }
    
    clock_t start_time = clock();
    
    int result = chineseRemainder(a, m, k);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    if (result == -1) {
        printf("No solution exists (moduli must be pairwise coprime).\n");
    } else {
        printf("Solution: x ≡ %d (mod %d)\n", result, m[0] * m[1] * (k > 1 ? m[2] * (k > 2 ? m[3] : 1) : 1));
    }
    printf("Time taken for execution: %f seconds\n", time_taken);
    
    return 0;
}