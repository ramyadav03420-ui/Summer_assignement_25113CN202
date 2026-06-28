#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; 
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void add_book();
void display_books();
void search_book();
void issue_book();
void return_book();
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                issue_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                printf("\nThank you for using the Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library database is full!\n");
        return;
    }

    struct Book new_book;
    
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &new_book.id);
    clear_input_buffer(); 

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("\nError: A book with ID %d already exists.\n", new_book.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; 

    new_book.is_issued = 0;
    library[book_count] = new_book;
    book_count++;

    printf("\nSuccess: Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("\nThe library is empty. No records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-30s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n---------------------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-30s %-30s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n---------------------------------------------------------------------------------\n");
}

void search_book() {
    if (book_count == 0) {
        printf("\nThe library is empty.\n");
        return;
    }

    int search_id;
    printf("\nEnter the Book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", search_id);
}

void issue_book() {
    int issue_id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued == 1) {
                printf("\nError: This book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nSuccess: Book successfully issued!\n");
            }
            return;
        }
    }
    printf("\nError: Book with ID %d does not exist.\n", issue_id);
}

void return_book() {
    int return_id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (library[i].is_issued == 0) {
                printf("\nError: This book is already in the library inventory.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nSuccess: Book successfully returned!\n");
            }
            return;
        }
    }
    printf("\nError: Book with ID %d does not belong to this library.\n", return_id);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
