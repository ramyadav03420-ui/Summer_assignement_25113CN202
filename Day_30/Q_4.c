#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 30

void addStudents(char names[][NAME_LENGTH], int scores[], int *count);
void displayStudents(char names[][NAME_LENGTH], int scores[], int count);
void calculateStatistics(int scores[], int count);
void searchStudent(char names[][NAME_LENGTH], int scores[], int count);
void clearInputBuffer();

int main() {
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    int studentScores[MAX_STUDENTS];
    int currentStudentCount = 0;
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Students\n");
        printf("2. Display All Student Records\n");
        printf("3. View Performance Statistics\n");
        printf("4. Search for a Student by Name\n");
        printf("5. Exit Project\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); 

        switch (choice) {
            case 1:
                addStudents(studentNames, studentScores, &currentStudentCount);
                break;
            case 2:
                displayStudents(studentNames, studentScores, currentStudentCount);
                break;
            case 3:
                calculateStatistics(studentScores, currentStudentCount);
                break;
            case 4:
                searchStudent(studentNames, studentScores, currentStudentCount);
                break;
            case 5:
                printf("Exiting system. Project execution completed successfully.\n");
                break;
            default:
                printf("Invalid option. Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudents(char names[][NAME_LENGTH], int scores[], int *count) {
    int numToAdd, i;
    printf("How many students do you want to add? ");
    scanf("%d", &numToAdd);
    clearInputBuffer();

    if (*count + numToAdd > MAX_STUDENTS) {
        printf("Error: Operation exceeds system maximum limit of %d students.\n", MAX_STUDENTS);
        return;
    }

    for (i = 0; i < numToAdd; i++) {
        printf("\nEnter details for Student %d:\n", *count + 1);
        printf("Enter full name: ");
        
        fgets(names[*count], NAME_LENGTH, stdin);
        names[*count][strcspn(names[*count], "\n")] = '\0'; 

        printf("Enter exam score (0-100): ");
        scanf("%d", &scores[*count]);
        clearInputBuffer();
        
        (*count)++;
    }
    printf("\nSuccessfully added %d student(s).\n", numToAdd);
}

void displayStudents(char names[][NAME_LENGTH], int scores[], int count) {
    if (count == 0) {
        printf("\nThe database is currently empty. No student records found.\n");
        return;
    }

    printf("\n%-5s | %-25s | %-6s\n", "ID", "Student Name", "Score");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d | %-25s | %-6d\n", i + 1, names[i], scores[i]);
    }
}

void calculateStatistics(int scores[], int count) {
    if (count == 0) {
        printf("\nNo data available to compute statistics.\n");
        return;
    }

    int total = 0, highest = scores[0], lowest = scores[0];
    
    for (int i = 0; i < count; i++) {
        total += scores[i];
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
    }
    
    double average = (double)total / count;

    printf("\n===== CLASS PERFORMANCE REPORT =====\n");
    printf("Total Students Processed : %d\n", count);
    printf("Class Grade Average      : %.2f\n", average);
    printf("Highest Score Achieved   : %d\n", highest);
    printf("Lowest Score Achieved    : %d\n", lowest);
}

void searchStudent(char names[][NAME_LENGTH], int scores[], int count) {
    if (count == 0) {
        printf("\nThe database is currently empty. Cannot search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    int found = 0;

    printf("Enter the full name of the student to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("\nMatch Found! -> ID: %d | Name: %s | Score: %d\n", i + 1, names[i], scores[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found. Ensure exact string matches and capitalization.\n");
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
