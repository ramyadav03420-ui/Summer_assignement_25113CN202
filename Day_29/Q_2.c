#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 
void createArray(int arr[], int *size);
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n   ARRAY OPERATIONS SYSTEM Menu  ");
        printf("\n=================================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert Element at Position");
        printf("\n4. Delete Element from Position");
        printf("\n5. Search Element (Linear Search)");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("\nExiting System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter the number of elements to initialize (Max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Error: Invalid size! Cannot exceed max limit.\n");
        return;
    }

    *size = n;
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\nTotal Elements: %d\n", size);
}

void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, pos;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", *size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position! Placement failed.\n");
        return;
    }

    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = element; 
    (*size)++;              
    printf("Element inserted successfully!\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array Underflow! No elements to delete.\n");
        return;
    }

    int pos;
    printf("\nEnter the position to delete (1 to %d): ", *size);
    scanf("%d", &pos);

    if (pos < 1 || pos > *size) {
        printf("Invalid position! Deletion failed.\n");
        return;
    }

    int deletedValue = arr[pos - 1];

    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; 
    printf("Deleted element '%d' from position %d successfully!\n", deletedValue, pos);
}

void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to search.\n");
        return;
    }

    int target, found = 0;
    printf("\nEnter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element '%d' found at 1-based position: %d (0-based Index: %d)\n", target, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element '%d' not found in the array.\n", target);
    }
}
