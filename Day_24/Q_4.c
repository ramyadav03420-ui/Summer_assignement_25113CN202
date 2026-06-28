#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int seen[256] = {0}; 
    
    int readIndex = 0;
    int writeIndex = 0;

    while (str[readIndex] != '\0') {
        unsigned char currentChar = str[readIndex];

        if (seen[currentChar] == 0) {
            seen[currentChar] = 1;        
            str[writeIndex] = str[readIndex]; 
            writeIndex++;
        }
        readIndex++;
    }
    
    str[writeIndex] = '\0'; 
}

int main() {
    char str[] = "programming language";

    printf("Original String: %s\n", str);

    removeDuplicates(str);

    printf("Result String  : %s\n", str);

    return 0;
}
