#include <stdio.h>
#include <string.h>

char findFirstRepeating(char *str) {
    int count[256] = {0};

    for (int i = 0; i < strlen(str); i++) {
        unsigned char ch = str[i];

        if (count[ch] > 0) {
            return ch;
        }

        count[ch]++;
    }

    return '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("There are no repeating characters.\n");
    }

    return 0;
}
