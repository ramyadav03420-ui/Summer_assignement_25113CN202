#include <stdio.h>

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0; 
        } 
        else if (in_word == 0) {
            in_word = 1; 
            count++;     
        }
    }
    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int total_words = count_words(sentence);
    printf("Total number of words: %d\n", total_words);

    return 0;
}
