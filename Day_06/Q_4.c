#include <stdio.h>

double calculate_power(double x, long long n) {
    if (n == 0) {
        return 1.0;
    }
    
    if (n < 0) {
        x = 1.0 / x;
        n = -n; 
    }
    
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    
    return result;
}

int main() {
    double x;
    long long n;

    printf("Enter the base (x): ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid base input.\n");
        return 1;
    }

    printf("Enter the exponent (n): ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid exponent input.\n");
        return 1;
    }

    if (x == 0.0 && n <= 0) {
        if (n == 0) {
            printf("0^0 is mathematically undefined or commonly evaluated to 1.0\n");
        } else {
            printf("Error: Division by zero (0 raised to a negative power).\n");
            return 1;
        }
    }

    double result = calculate_power(x, n);

    printf("%.6f raised to the power of %lld is: %g\n", x, n, result);

    return 0;
}
