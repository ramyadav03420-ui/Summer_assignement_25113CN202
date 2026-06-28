#include <stdio.h>
#include <stdbool.h>

void displayMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    const int DEFAULT_PIN = 1234;
    double balance = 5000.00; 
    
    int enteredPin;
    int pinAttempts = 0;
    const int MAX_ATTEMPTS = 3;
    bool isAuthenticated = false;

    printf("=== WELCOME TO THE ATM SYSTEM ===\n");

    while (pinAttempts < MAX_ATTEMPTS) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input! Please enter numbers only.\n\n");
            while (getchar() != '\n');
            pinAttempts++;
            continue;
        }

        if (enteredPin == DEFAULT_PIN) {
            isAuthenticated = true;
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", MAX_ATTEMPTS - pinAttempts);
        }
    }

    if (!isAuthenticated) {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        return 0;
    }

    int choice;
    do {
        displayMenu();
        printf("Choose an option (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please pick a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n---------- ATM MENU ----------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

void checkBalance(double balance) {
    printf("\nYour current balance is: $%.2f\n", balance);
}

double depositMoney(double balance) {
    double amount;
    printf("\nEnter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be greater than zero.\n");
    } else {
        balance += amount;
        printf("Successfully deposited: $%.2f\n", amount);
        printf("New balance: $%.2f\n", balance);
    }
    return balance;
}

double withdrawMoney(double balance) {
    double amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be greater than zero.\n");
    } else if (amount > balance) {
        printf("Transaction Denied! Insufficient funds available.\n");
    } else {
        balance -= amount;
        printf("Successfully withdrew: $%.2f\n", amount);
        printf("Remaining balance: $%.2f\n", balance);
    }
    return balance;
}
