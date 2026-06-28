#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 

char findFirstUniqueChar(const char *str) {
    int freq[MAX_CHAR] = {0}; 
    
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0'; 
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        
        char result = findFirstUniqueChar(str);
        
        if (result != '\0') {
            printf("The first non-repeating character is: '%c'\n", result);
        } else {
            printf("All characters are repeating or the string is empty.\n");
        }
    }
    
    return 0;
}
