// Create a Structure called BankMgmt with AccNumber, CustName, AvlBalance,
// AccType as members. Implement a Bank management Application as menu driven
// program for the above said Structure scenario.
// Menu Option:
// 1. Withdrawal 2. Deposit 3. Display Balance 4. Exit
// If option
// 1 is chosen- Amount can be withdrawn from the account (Withdrawn amount
// should be given as input). For withdrawal the condition is- the AvlBalance must be
// greater than withdrawn amount).
// 2 is chosen- Amount can be deposited to the account (the deposited amount
// should be given as input). The deposited amount should be reflected in AvlBalance of
// the account.
// 3 is chosen- Current available balance (AvlBalance) of the AccNumber should
// be Displayed with other details
// 4 is chosen- Exit from the application
// Sample Input:
// SB 100155 VenkatKrishna 4500.00 Saving

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankmgmt{    // stucture for storing details of customer
    long int account_number;
    char customer_name[50];
    int available_balance;
    char account_type[10];
};

int main(){
    struct bankmgmt *customer1= (struct bankmgmt *)malloc(sizeof(struct bankmgmt));
    printf("Enter customer's account number : ");
    scanf("%d",&customer1->account_number);
    getchar(); // Consume the leftover newline character

    printf("Enter customer's name : ");
    fgets(customer1->customer_name, sizeof(customer1->customer_name), stdin);
    customer1->customer_name[strcspn(customer1->customer_name, "\n")] = '\0'; // Remove newline
    printf("Enter customer's available balance : ");
    scanf("%d",&customer1->available_balance);
    printf("Enter customer's account type  1: saving \n 2: current: ");
    scanf("%s",customer1->account_type);

    printf("enter choice :\n");
    printf("1. Withdrawal \n2. Deposit \n3. Display Balance \n4. Exit\n");
    int choice;
    scanf("%d",&choice);

    switch(choice){

        case 1:
            printf("enter amount to withdraw : \n");
            int withdrawal_amount;
            scanf("%d",&withdrawal_amount);
            if(withdrawal_amount>customer1->available_balance){
                printf("insufficient balance \n");
            }
            else{
                customer1->available_balance = customer1->available_balance - withdrawal_amount;
            }
            printf("available balance : %d\n",customer1->available_balance);
            break;
        case 2: 
            printf("enter amount to deposit : \n");
            int deposit_amount;
            scanf("%d",&deposit_amount);
            customer1->available_balance = customer1->available_balance + deposit_amount;
            printf("available balance : %d\n",customer1->available_balance);
            break; 
        case 3:
            printf("available balance : %d\n",customer1->available_balance);
            break;
        case 4:
            break;            
    }
    free(customer1);
    return 0;
}
