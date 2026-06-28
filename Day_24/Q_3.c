#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    char longest_word[1000] = "";
    char current_word[1000] = "";
    int i = 0, j = 0;
    int max_length = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    while (sentence[i] != '\0') {
        if (isalnum((unsigned char)sentence[i])) {
            current_word[j++] = sentence[i];
        } 
        else {
            if (j > 0) {
                current_word[j] = '\0'; 
                
                if (j > max_length) {
                    max_length = j;
                    strcpy(longest_word, current_word);
                }
                j = 0; 
            }
        }
        i++;
    }

    if (j > max_length) {
        current_word[j] = '\0';
        max_length = j;
        strcpy(longest_word, current_word);
    }

    if (max_length > 0) {
        printf("The longest word is: \"%s\"\n", longest_word);
        printf("Length of the longest word: %d\n", max_length);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}
