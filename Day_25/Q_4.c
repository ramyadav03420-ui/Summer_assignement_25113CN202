#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LENGTH 20

int compare_word_lengths(const void *a, const void *b) {
    size_t len_a = strlen((const char *)a);
    size_t len_b = strlen((const char *)b);
    
    return (len_a > len_b) - (len_a < len_b);
}

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {
        "Elephant",
        "Cat",
        "Hippopotamus",
        "Dog",
        "Monkey"
    };

    printf("Original word list:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("- %s\n", words[i]);
    }

    qsort(words, MAX_WORDS, MAX_LENGTH, compare_word_lengths);

    printf("\nWords sorted by length (ascending):\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("- %s (Length: %zu)\n", words[i], strlen(words[i]));
    }

    return 0;
}
