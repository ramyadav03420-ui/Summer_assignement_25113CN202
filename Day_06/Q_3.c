#include <stdio.h>

int countSetBits(unsigned int n) {
    int count = 0;
    
    while (n > 0) {
        n &= (n - 1); 
        count++;      
    }
    
    return count;
}

int main() {
    unsigned int num;

    printf("Enter an integer: ");
    if (scanf("%u", &num) == 1) {
        int result = countSetBits(num);
        printf("Number of set bits in %u is: %d\n", num, result);
    }

    return 0;
}
