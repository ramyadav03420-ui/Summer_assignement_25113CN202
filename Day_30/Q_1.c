#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student system[], int *count);
void displayStudents(struct Student system[], int count);
void searchStudent(struct Student system[], int count);

int main() {
    struct Student recordSystem[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting system.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(recordSystem, &studentCount);
                break;
            case 2:
                displayStudents(recordSystem, studentCount);
                break;
            case 3:
                searchStudent(recordSystem, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

void addStudent(struct Student system[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("System Error: Maximum storage capacity reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &system[*count].roll_no);
    
    while (getchar() != '\n'); 

    printf("Enter Student Name: ");
    fgets(system[*count].name, NAME_LENGTH, stdin);
    
    system[*count].name[strcspn(system[*count].name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &system[*count].marks);

    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(struct Student system[], int count) {
    if (count == 0) {
        printf("\nNo student records found in the system.\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", system[i].roll_no, system[i].name, system[i].marks);
    }
    printf("---------------------------------------------\n");
}

void searchStudent(struct Student system[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (system[i].roll_no == searchRoll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", system[i].roll_no);
            printf("Name       : %s\n", system[i].name);
            printf("Marks      : %.2f\n", system[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchRoll);
    }
}
