#include <stdio.h>
#include <stdbool.h>


bool isPrime(int num) {
    
    if (num <= 1) {
        return false;
    }
    
    
    if (num == 2) {
        return true;
    }
    
    if (num % 2 == 0) {
        return false;
    }
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false; 
        }
    }
    
    return true; 
}

int main() {
    int start, end;

    
    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    printf("\nPrime numbers between %d and %d are:\n", start, end);
    
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }

    if (count == 0) {
        printf("None found.");
    }
    
    printf("\n");
    return 0;
}