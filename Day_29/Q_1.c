#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    
    do {
        printf("\n=============================\n");
        printf("    MENU-DRIVEN CALCULATOR   \n");
        printf("=============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid choice! Please select an option between 1 and 5.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0.0) {
                    printf("\nError: Division by zero is mathematically undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default:
                printf("\nError: Unexpected system issue.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
