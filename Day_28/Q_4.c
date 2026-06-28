#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"
#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50

struct Contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
};

void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("    CONTACT MANAGEMENT SYSTEM    \n");
        printf("==================================\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Edit Contact Information\n");
        printf("5. Delete a Contact\n");
        printf("6. Exit System\n");
        printf("==================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); 

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("\nThank you for using Contact Management System!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Choose a number between 1 and 6.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char *buffer, int max_len) {
    fgets(buffer, max_len, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 
}

void addContact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    struct Contact c;
    printf("\nEnter Name: ");
    readString(c.name, MAX_NAME);
    printf("Enter Phone Number: ");
    readString(c.phone, MAX_PHONE);
    printf("Enter Email Address: ");
    readString(c.email, MAX_EMAIL);

    fprintf(file, "%s\n%s\n%s\n", c.name, c.phone, c.email);
    fclose(file);

    printf("\nContact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo contacts found. The file is empty or missing.\n");
        return;
    }

    struct Contact c;
    int count = 1;
    printf("\n%-5s %-25s %-15s %-25s\n", "S.No", "Name", "Phone", "Email");
    printf("------------------------------------------------------------------------\n");

    while (fgets(c.name, MAX_NAME, file) && 
           fgets(c.phone, MAX_PHONE, file) && 
           fgets(c.email, MAX_EMAIL, file)) {
        
        c.name[strcspn(c.name, "\n")] = '\0';
        c.phone[strcspn(c.phone, "\n")] = '\0';
        c.email[strcspn(c.email, "\n")] = '\0';

        printf("%-5d %-25s %-15s %-25s\n", count++, c.name, c.phone, c.email);
    }
    
    if (count == 1) {
        printf("No valid contact records found.\n");
    }
    fclose(file);
}

void searchContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    char searchName[MAX_NAME];
    struct Contact c;
    int found = 0;

    printf("\nEnter the name to search: ");
    readString(searchName, MAX_NAME);

    printf("\nSearch Results:\n");
    printf("------------------------------------------------------------------------\n");
    while (fgets(c.name, MAX_NAME, file) && 
           fgets(c.phone, MAX_PHONE, file) && 
           fgets(c.email, MAX_EMAIL, file)) {
        
        c.name[strcspn(c.name, "\n")] = '\0';
        c.phone[strcspn(c.phone, "\n")] = '\0';
        c.email[strcspn(c.email, "\n")] = '\0';

        if (strstr(c.name, searchName) != NULL) {
            printf("Name : %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            printf("------------------------------------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching '%s'.\n", searchName);
    }
    fclose(file);
}

void editContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo contacts available to edit.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("\nError processing data updates!\n");
        fclose(file);
        return;
    }

    char targetName[MAX_NAME];
    struct Contact c;
    int found = 0;

    printf("\nEnter the EXACT name of the contact you want to edit: ");
    readString(targetName, MAX_NAME);

    while (fgets(c.name, MAX_NAME, file) && 
           fgets(c.phone, MAX_PHONE, file) && 
           fgets(c.email, MAX_EMAIL, file)) {
        
        c.name[strcspn(c.name, "\n")] = '\0';
        c.phone[strcspn(c.phone, "\n")] = '\0';
        c.email[strcspn(c.email, "\n")] = '\0';

        if (strcmp(c.name, targetName) == 0) {
            found = 1;
            printf("\n--- Contact Found! Enter New Information ---\n");
            printf("Enter New Name: ");
            readString(c.name, MAX_NAME);
            printf("Enter New Phone: ");
            readString(c.phone, MAX_PHONE);
            printf("Enter New Email: ");
            readString(c.email, MAX_EMAIL);
        }
        fprintf(tempFile, "%s\n%s\n%s\n", c.name, c.phone, c.email);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\nContact updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("\nContact not found.\n");
    }
}

void deleteContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("\nError processing deletion!\n");
        fclose(file);
        return;
    }

    char targetName[MAX_NAME];
    struct Contact c;
    int found = 0;

    printf("\nEnter the EXACT name of the contact to delete: ");
    readString(targetName, MAX_NAME);

    while (fgets(c.name, MAX_NAME, file) && 
           fgets(c.phone, MAX_PHONE, file) && 
           fgets(c.email, MAX_EMAIL, file)) {
        
        c.name[strcspn(c.name, "\n")] = '\0';
        c.phone[strcspn(c.phone, "\n")] = '\0';
        c.email[strcspn(c.email, "\n")] = '\0';

        if (strcmp(c.name, targetName) == 0) {
            found = 1; 
            continue;
        }
        fprintf(tempFile, "%s\n%s\n%s\n", c.name, c.phone, c.email);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\nContact deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("\nContact not found.\n");
    }
}
