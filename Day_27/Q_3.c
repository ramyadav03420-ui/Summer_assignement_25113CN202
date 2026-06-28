#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;         
    float da;           
    float pf;         
    float net_salary;
};

void addEmployee();
void displayAllEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
void calculateSalaryComponents(struct Employee *emp);

const char *FILE_NAME = "salaries.dat";

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n      SALARY MANAGEMENT SYSTEM      ");
        printf("\n====================================");
        printf("\n1. Add Employee Salary Record");
        printf("\n2. Display All Salary Records");
        printf("\n3. Search Employee Salary Slip");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}

void calculateSalaryComponents(struct Employee *emp) {
    emp->hra = emp->basic_salary * 0.20;
    emp->da = emp->basic_salary * 0.10;  
    emp->pf = emp->basic_salary * 0.12; 
    emp->net_salary = (emp->basic_salary + emp->hra + emp->da) - emp->pf;
}

void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);

    calculateSalaryComponents(&emp);

    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);

    printf("\nRecord added successfully!\n");
}

void displayAllEmployees() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found! Add an employee first.\n");
        return;
    }

    struct Employee emp;
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-12s %-10s %-10s %-10s %-12s\n", "ID", "Name", "Basic", "HRA", "DA", "PF", "Net Salary");
    printf("----------------------------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        printf("%-5d %-20s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f\n", 
               emp.id, emp.name, emp.basic_salary, emp.hra, emp.da, emp.pf, emp.net_salary);
    }
    printf("----------------------------------------------------------------------------------------\n");
    fclose(file);
}

void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == searchId) {
            found = 1;
            printf("\n====================================");
            printf("\n           SALARY SLIP              ");
            printf("\n====================================");
            printf("\nEmployee ID   : %d", emp.id);
            printf("\nEmployee Name : %s", emp.name);
            printf("\n------------------------------------");
            printf("\nBasic Salary  : $%.2f", emp.basic_salary);
            printf("\nHRA (20%%)     : $%.2f", emp.hra);
            printf("\nDA (10%%)      : $%.2f", emp.da);
            printf("\nPF Ded. (12%%) : $%.2f", emp.pf);
            printf("\n------------------------------------");
            printf("\nNET SALARY    : $%.2f", emp.net_salary);
            printf("\n====================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee record with ID %d not found.\n", searchId);
    }
    fclose(file);
}

void modifyEmployee() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int modifyId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &modifyId);

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == modifyId) {
            found = 1;
            printf("\nCurrent Record: Name: %s, Basic Salary: %.2f\n", emp.name, emp.basic_salary);
            
            getchar(); 
            printf("Enter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Basic Salary: ");
            scanf("%f", &emp.basic_salary);

            calculateSalaryComponents(&emp);

            fseek(file, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, file);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee record with ID %d not found.\n", modifyId);
    }
    fclose(file);
}

void deleteEmployee() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("\nError processing request!\n");
        fclose(file);
        return;
    }

    int deleteId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == deleteId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nEmployee record with ID %d not found.\n", deleteId);
    }
}
