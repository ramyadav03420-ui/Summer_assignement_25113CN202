#include <stdio.h>
#include <string.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    char str1[200], str2[100];

    do {
        printf("\n====================================");
        printf("\n   STRING OPERATIONS SYSTEM MENU   ");
        printf("\n====================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        
        clearBuffer();

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; 
                
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                strcpy(str2, str1); 
                printf("Successfully copied! New string: %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                printf("Enter the string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated Result: %s\n", str1);
                } else {
                    printf("Error: Resulting string is too long for destination buffer.\n");
                }
                break;

            case 4:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                int cmpResult = strcmp(str1, str2);
                if (cmpResult == 0) {
                    printf("Result: Both strings are perfectly identical.\n");
                } else if (cmpResult > 0) {
                    printf("Result: First string is lexicographically greater.\n");
                } else {
                    printf("Result: Second string is lexicographically greater.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                int len = strlen(str1);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
