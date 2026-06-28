#include <stdio.h>

void removeSpaces(char *str) {
    int i = 0; 
    int j = 0; 

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char text[] = " C  Pro gra m m i n g ";

    printf("Original String: \"%s\"\n", text);

    removeSpaces(text);

    printf("Modified String: \"%s\"\n", text);

    return 0;
}
