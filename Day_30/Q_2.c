#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int is_issued; 
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n*** MINI LIBRARY SYSTEM MENU ***");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit Application");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nThank you for using the Mini Library System!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary capacity reached! Cannot add more books.\n");
        return;
    }

    struct Book new_book;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &new_book.id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with ID %d already exists!\n", new_book.id);
            return;
        }
    }

    getchar(); 

    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; 

    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; 

    new_book.is_issued = 0; 

    library[book_count] = new_book;
    book_count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n----------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-25s %-20s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n");
}

void searchBook() {
    if (book_count == 0) {
        printf("\nThe library is completely empty.\n");
        return;
    }

    int search_id;
    printf("\nEnter Book ID to search: ");
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

void issueBook() {
    int issue_id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued == 1) {
                printf("\nSorry, this book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nBook issued successfully!\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}

void returnBook() {
    int return_id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (library[i].is_issued == 0) {
                printf("\nThis book is already sitting in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nBook returned successfully!\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}
