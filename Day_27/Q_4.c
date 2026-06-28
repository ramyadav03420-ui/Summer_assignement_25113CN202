#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    float math;
    float science;
    float english;
    float computer;
    float history;
    float total;
    float percentage;
    char grade[3];
};

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float get_valid_mark(const char *subject_name) {
    float mark;
    while (1) {
        printf("Enter marks for %s (0 - 100): ", subject_name);
        if (scanf("%f", &mark) == 1) {
            if (mark >= 0.0f && mark <= 100.0f) {
                return mark;
            }
        } else {
            clear_buffer(); 
        }
        printf("⚠️ Invalid input! Marks must be a number between 0 and 100.\n");
    }
}

int main() {
    struct Student s;

    printf("===========================================\n");
    printf("     STUDENT MARKSHEET GENERATION SYSTEM   \n");
    printf("===========================================\n\n");

    printf("Enter Student Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; 

    printf("Enter Roll Number: ");
    while (scanf("%d", &s.roll_no) != 1 || s.roll_no <= 0) {
        printf("⚠️ Invalid input! Please enter a valid positive roll number: ");
        clear_buffer();
    }

    printf("\n--- Input Subject Marks ---\n");
    
    s.math = get_valid_mark("Mathematics");
    s.science = get_valid_mark("Science");
    s.english = get_valid_mark("English");
    s.computer = get_valid_mark("Computer Science");
    s.history = get_valid_mark("History");

    s.total = s.math + s.science + s.english + s.computer + s.history;
    s.percentage = (s.total / 500.0f) * 100.0f;

    if (s.percentage >= 90.0f) {
        strcpy(s.grade, "A+");
    } else if (s.percentage >= 80.0f) {
        strcpy(s.grade, "A");
    } else if (s.percentage >= 70.0f) {
        strcpy(s.grade, "B");
    } else if (s.percentage >= 60.0f) {
        strcpy(s.grade, "C");
    } else if (s.percentage >= 50.0f) {
        strcpy(s.grade, "D");
    } else if (s.percentage >= 40.0f) {
        strcpy(s.grade, "E");
    } else {
        strcpy(s.grade, "F");
    }

    printf("\n\n");
    printf("############################################################\n");
    printf("#                    OFFICIAL REPORT CARD                  #\n");
    printf("############################################################\n");
    printf("  Student Name : %-35s   \n", s.name);
    printf("  Roll Number  : %-10d                                \n", s.roll_no);
    printf("------------------------------------------------------------\n");
    printf("  SUBJECT                  MAX MARKS       OBTAINED MARKS   \n");
    printf("------------------------------------------------------------\n");
    printf("  Mathematics                 100               %6.2f      \n", s.math);
    printf("  Science                     100               %6.2f      \n", s.science);
    printf("  English                     100               %6.2f      \n", s.english);
    printf("  Computer Science            100               %6.2f      \n", s.computer);
    printf("  History                     100               %6.2f      \n", s.history);
    printf("------------------------------------------------------------\n");
    printf("  TOTAL                       500               %6.2f      \n", s.total);
    printf("------------------------------------------------------------\n");
    printf("  PERCENTAGE   : %6.2f%%                                    \n", s.percentage);
    printf("  FINAL GRADE  : %-2s                                         \n", s.grade);
    printf("  STATUS       : %-8s                                     \n", 
           (strcmp(s.grade, "F") == 0) ? "FAIL ❌" : "PASS  ");
    printf("############################################################\n");

    return 0;
}
