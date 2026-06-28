#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     EMPLOYEE MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                modifyEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("\nExiting the program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Add an employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nDatabase full! Cannot add more records.\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("\nError: Employee ID %d already exists!\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount] = emp;
    employeeCount++;
    printf("\nEmployee record added successfully!\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------");
    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n-------------------------------------------------------------------");
    for (int i = 0; i < employeeCount; i++) {
        printf("\n%-10d %-20s %-20s %-10.2f", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
    printf("\n-------------------------------------------------------------------\n");
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found to search.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nRecord Found:");
            printf("\nID: %d", employees[i].id);
            printf("\nName: %s", employees[i].name);
            printf("\nDesignation: %s", employees[i].designation);
            printf("\nSalary: %.2f\n", employees[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}

void modifyEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found to modify.\n");
        return;
    }

    int modifyId, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &modifyId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == modifyId) {
            printf("\nCurrent Details: Name: %s, Desg: %s, Salary: %.2f", 
                   employees[i].name, employees[i].designation, employees[i].salary);
            
            printf("\n\nEnter New Name: ");
            getchar(); 
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
            employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);

            printf("\nRecord updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", modifyId);
    }
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found to delete.\n");
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("\nRecord deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", deleteId);
    }
}
