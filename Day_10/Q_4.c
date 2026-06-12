#include <stdio.h>

int main() {
    int total_rows = 5; 

    for (int i = 1; i <= total_rows; i++) {
        for (int space = 1; space <= total_rows - i; space++) {
            printf(" ");
        }

        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            printf("%c", ch);
            ch++;
        }

        ch -= 2; 
        for (int j = 1; j < i; j++) {
            printf("%c", ch);
            ch--;
        }

        printf("\n");
    }

    return 0;
}
