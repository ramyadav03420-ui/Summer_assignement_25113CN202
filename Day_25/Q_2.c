#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 26

int min(int a, int b) {
    return (a < b) ? a : b;
}

void findCommonCharacters(char strings[][100], int n) {
    int min_freq[MAX_CHAR];
    
    for (int i = 0; i < MAX_CHAR; i++) {
        min_freq[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        int current_freq[MAX_CHAR] = {0};

        for (int j = 0; strings[i][j] != '\0'; j++) {
            // Check if character is a lowercase letter
            if (strings[i][j] >= 'a' && strings[i][j] <= 'z') {
                current_freq[strings[i][j] - 'a']++;
            }
        }

        for (int j = 0; j < MAX_CHAR; j++) {
            min_freq[j] = min(min_freq[j], current_freq[j]);
        }
    }

    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        while (min_freq[i] > 0) {
            printf("%c ", i + 'a');
            min_freq[i]--;
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char strings[][100] = {
        "bella",
        "label",
        "roller"
    };
    
    int n = sizeof(strings) / sizeof(strings[0]);

    printf("Input strings:\n");
    for (int i = 0; i < n; i++) {
        printf("  - %s\n", strings[i]);
    }

    findCommonCharacters(strings, n);

    return 0;
}
