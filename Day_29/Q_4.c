#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void clearInputBuffer();
void addItem();
void displayInventory();
void searchItem();
void updateStock();
void deleteItem();

int main() {
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("     INVENTORY MANAGEMENT SYSTEM    \n");
        printf("===================================\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Stock/Price\n");
        printf("5. Delete Item\n");
        printf("6. Exit System\n");
        printf("===================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Inventory capacity full!\n");
        return;
    }

    Item newItem;
    printf("\nEnter Unique Product ID (Integer): ");
    if (scanf("%d", &newItem.id) != 1) {
        printf("Invalid ID format.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: Item with ID %d already exists!\n", newItem.id);
            return;
        }
    }

    clearInputBuffer();
    printf("Enter Product Name: ");
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; 

    printf("Enter Quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("Invalid quantity.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Price ($): ");
    if (scanf("%f", &newItem.price) != 1 || newItem.price < 0.0) {
        printf("Invalid price.\n");
        clearInputBuffer();
        return;
    }

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Success: Item added successfully!\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "ID", "Product Name", "Quantity", "Price ($)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-12d %-10.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

void searchItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty. Nothing to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Product ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input type.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

void updateStock() {
    if (itemCount == 0) {
        printf("\nInventory is empty. Nothing to update.\n");
        return;
    }

    int searchId;
    printf("\nEnter Product ID to update: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input type.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nCurrent Data -> Name: %s | Stock: %d | Price: $%.2f\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Price ($): ");
            scanf("%f", &inventory[i].price);
            
            printf("Success: Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

void deleteItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty. Nothing to delete.\n");
        return;
    }

    int searchId;
    printf("\nEnter Product ID to delete: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input type.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Success: Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}
