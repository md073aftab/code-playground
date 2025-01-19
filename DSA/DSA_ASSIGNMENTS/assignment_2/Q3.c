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

struct bankmgmt{    // stucture for storing details of customer
    int account_number;
    char customer_name[50];
    int available_balance;
    char account_type[10];
};

int main(){
    struct bankmgmt *customer1= (struct bankmgmt *)malloc(sizeof(struct bankmgmt));
    printf("Enter customer's account number : ");
    scanf("%d",&customer1->account_number);
    printf("Enter customer's name : ");
    scanf("%s",&customer1->customer_name);
    printf("Enter customer's available balance : ");
    scanf("%d",&customer1->available_balance);
    printf("Enter customer's account type : ");
    scanf("%d",&customer1->account_type);

    printf("enter choice :\n");
    printf("1. Withdrawal \n2. Deposit \n3. Display Balance \n4. Exit\n");
    int choice;
    scanf("%d",&choice);

    switch(choice)

    case 1:
        
    return 0;
}
