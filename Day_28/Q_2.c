#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

void createAccount(Account accounts[], int *numAccounts);
void depositMoney(Account accounts[], int numAccounts);
void withdrawMoney(Account accounts[], int numAccounts);
void checkBalance(Account accounts[], int numAccounts);
int findAccount(Account accounts[], int numAccounts, int accNo);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    do {
        printf("\n=== BANK ACCOUNT SYSTEM ===\n");
        printf("1. Create New Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\n");
        printf("Enter choice (1-5): ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); continue; }

        switch (choice) {
            case 1: createAccount(accounts, &numAccounts); break;
            case 2: depositMoney(accounts, numAccounts); break;
            case 3: withdrawMoney(accounts, numAccounts); break;
            case 4: checkBalance(accounts, numAccounts); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}

void createAccount(Account accounts[], int *numAccounts) { /* ... */ }
void depositMoney(Account accounts[], int numAccounts) { /* ... */ }
void withdrawMoney(Account accounts[], int numAccounts) { /* ... */ }
void checkBalance(Account accounts[], int numAccounts) { /* ... */ }
int findAccount(Account accounts[], int numAccounts, int accNo) { /* ... */ }
