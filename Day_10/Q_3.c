#include <stdio.h>

int main() {
    int rows = 5; 
    
    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        printf("\n");
    }
    return 0;
}
