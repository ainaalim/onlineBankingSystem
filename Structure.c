#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct Account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    // Additional account information
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to create a new account
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }
    
    struct Account newAccount;
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);
    // Additional input for account information if needed
    
    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("Account created successfully!\n");
}

// Function to update an existing account
void updateAccount() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", accounts[i].password);
            // Additional updates for account information if needed
            
            printf("Account updated successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

// Function to delete an existing account
void deleteAccount() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            // Shift remaining accounts to fill the gap
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            printf("Account deleted successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

// Function to authenticate a user
int authenticate() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            printf("Authentication successful!\n");
            return 1;
        }
    }

    printf("Authentication failed!\n");
    return 0;
}

int main() {
    int choice;

    while (1) {
        printf("1. Create account\n");
        printf("2. Update account\n");
        printf("3. Delete account\n");
        printf("4. Authenticate\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                updateAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                authenticate();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
