#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0; 
    int len = strlen(src);

    while (i < len) {
        dest[j++] = src[i];
        
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        
        int written = sprintf(&dest[j], "%d", count);
        j += written;
        
        i++; 
    }
    
    dest[j] = '\0'; 
}

int main() {
    char input[100];
    char compressed[200]; 

    printf("Enter a string to compress: ");
    if (scanf("%99s", input) == 1) {
        compressString(input, compressed);
        
        printf("Original String:   %s\n", input);
        printf("Compressed String: %s\n", compressed);
    }

    return 0;
}
