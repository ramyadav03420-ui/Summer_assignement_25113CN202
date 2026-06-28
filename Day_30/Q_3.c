#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

void addEmployee();
void viewEmployees();
void searchEmployee();
void deleteEmployee();
void flushInput();

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flushInput();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    flushInput();

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    printf("Employee record added successfully!\n");
}

void viewEmployees() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo records found. Please add an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n--------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("--------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("%-10d %-20s %-20s $%-9.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("--------------------------------------------------------------\n");
    fclose(file);
}

void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Designation: %s\n", emp.designation);
            printf("Salary: $%.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(file);
}

void deleteEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Internal system error!\n");
        fclose(file);
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == targetId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Employee record deleted successfully!\n");
    } else {
        remove("temp.dat"); // clean up temp file
        printf("Employee with ID %d not found.\n", targetId);
    }
}
