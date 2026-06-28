#include <stdio.h>
#include <ctype.h> 

int main() {
    char str[100];

    printf("Enter a string in lowercase: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("String in uppercase: %s", str);

    return 0;
}
