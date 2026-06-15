#include <stdio.h>

int main() {
    long long num;
    long long largest_factor = 0;

    printf("Enter a positive number: ");
    scanf("%lld", &num);

    while (num % 2 == 0) {
        largest_factor = 2;
        num = num / 2; 
    }

    for (long long i = 3; i <= num; i += 2) {
        while (num % i == 0) {
            largest_factor = i; 
            num = num / i;      
        }
    }

    printf("The largest prime factor is: %lld\n", largest_factor);

    return 0;
}