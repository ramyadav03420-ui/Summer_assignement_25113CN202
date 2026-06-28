#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

int main() {
    char str[1000];
    int freq[ASCII_SIZE] = {0}; 
    int max_count = 0;
    char max_char = '\0';

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char index = (unsigned char)str[i];
        freq[index]++;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char index = (unsigned char)str[i];
        if (freq[index] > max_count) {
            max_count = freq[index];
            max_char = str[i];
        }
    }

    if (max_count > 0) {
        printf("The maximum occurring character is '%c' (appears %d times).\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
