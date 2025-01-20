#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankmgmt { // Structure for storing details of customer
    long int account_number;
    char customer_name[50];
    int available_balance;
    char account_type[10];
};

int main() {
    struct bankmgmt *customer1 = (struct bankmgmt *)malloc(sizeof(struct bankmgmt));
    if (customer1 == NULL) { 
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter customer's account number: ");
    scanf("%ld", &customer1->account_number); 
    getchar(); // Consume the leftover newline character

    printf("Enter customer's name: ");
    fgets(customer1->customer_name, sizeof(customer1->customer_name), stdin);
    customer1->customer_name[strcspn(customer1->customer_name, "\n")] = '\0'; // Remove newline

    printf("Enter customer's available balance: ");
    scanf("%d", &customer1->available_balance);

    printf("Enter customer's account type (Saving/Current): ");
    scanf("%s", customer1->account_type);

    int choice;
    do {
        printf("\nEnter choice:\n");
        printf("1. Withdrawal\n2. Deposit\n3. Display Balance\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter amount to withdraw: ");
                int withdrawal_amount;
                scanf("%d", &withdrawal_amount);
                if (withdrawal_amount > customer1->available_balance) {
                    printf("Insufficient balance.\n");
                } else {
                    customer1->available_balance -= withdrawal_amount;
                    printf("Withdrawal successful. Available balance: %d\n", customer1->available_balance);
                }
                break;
            }
            case 2: {
                printf("Enter amount to deposit: ");
                int deposit_amount;
                scanf("%d", &deposit_amount);
                customer1->available_balance += deposit_amount;
                printf("Deposit successful. Available balance: %d\n", customer1->available_balance);
                break;
            }
            case 3: {
                printf("\n--- Account Details ---\n");
                printf("Account Number: %ld\n", customer1->account_number);
                printf("Customer Name: %s\n", customer1->customer_name);
                printf("Available Balance: %d\n", customer1->available_balance);
                printf("Account Type: %s\n", customer1->account_type);
                break;
            }
            case 4:
                printf("Exiting application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free(customer1); // Free allocated memory
    return 0;
}
