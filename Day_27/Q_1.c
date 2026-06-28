#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;

void addStudent();
void displayAll();
void searchStudent();
void updateStudent();
void deleteStudent();
int rollExists(int roll);

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

int rollExists(int roll) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return 0;

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            fclose(fp);
            return 1; 
        }
    }
    fclose(fp);
    return 0; 
}

void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Append binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);

    if (rollExists(s.roll_no)) {
        printf("Error: Student with Roll Number %d already exists!\n", s.roll_no);
        fclose(fp);
        return;
    }

    getchar(); 
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}

void displayAll() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo records found. Add a student first!\n");
        return;
    }

    Student s;
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("-------------------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-10d %-20s %-15s %-5.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    printf("-------------------------------------------------------------\n");
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int roll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", s.roll_no);
            printf("Name:        %s\n", s.name);
            printf("Course:      %s\n", s.course);
            printf("GPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
    fclose(fp);
}

void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb+"); 
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int roll, found = 0;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            found = 1;
            
            printf("\nCurrent Data: Name: %s, Course: %s, GPA: %.2f\n", s.name, s.course, s.gpa);
            printf("Enter New Name: ");
            getchar(); 
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = '\0';

            printf("Enter New GPA: ");
            scanf("%f", &s.gpa);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    FILE *fp_temp = fopen("temp.dat", "wb");
    if (fp_temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&s, sizeof(Student), 1, fp_temp);
        }
    }

    fclose(fp);
    fclose(fp_temp);

    if (found) {
        remove(FILE_NAME);            
        rename("temp.dat", FILE_NAME); 
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat"); 
        printf("Student with Roll Number %d not found.\n", roll);
    }
}
