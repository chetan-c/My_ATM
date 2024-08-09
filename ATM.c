#include <stdio.h>

float withdraw(float balance);
float checkBalance(float balance);
float deposit(float balance);
float transferMoney(float balance);

int main()
{
    float balance = 1000000;
    int operation;

    while(1) {
        printf("\nWelcome To ATM\n");
        printf("Tell me what I can do for you:\n");
        printf("1. Withdraw\n");
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Money Transfer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                balance = withdraw(balance);
                break;

            case 2:
                checkBalance(balance);
                break;

            case 3:
                balance = deposit(balance);
                break;

            case 4:
                balance = transferMoney(balance);
                break;

            case 5:
                printf("Thank you for using our ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

float withdraw(float balance)
{
    float withdrawAmount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%f", &withdrawAmount);
    if (withdrawAmount > balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Withdrawn amount: %.2f\n", withdrawAmount);
        balance -= withdrawAmount;
        printf("Remaining balance: %.2f\n", balance);
    }
    return balance;
}

float checkBalance(float balance)
{
    printf("Current balance: %.2f\n", balance);
    return balance;
}

float deposit(float balance)
{
    float depositAmount;
    printf("Enter the amount you want to deposit: ");
    scanf("%f", &depositAmount);
    balance += depositAmount;
    printf("Deposited amount: %.2f\n", depositAmount);
    printf("Total balance now: %.2f\n", balance);
    return balance;
}

float transferMoney(float balance)
{
    float transferAmount;
    char person[50];
    printf("Enter the name of the person you want to transfer money to: ");
    scanf("%s", person);
    printf("Enter the amount you want to transfer: ");
    scanf("%f", &transferAmount);
    if (transferAmount > balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("%.2f transferred to %s\n", transferAmount, person);
        balance -= transferAmount;
        printf("Remaining balance: %.2f\n", balance);
    }
    return balance;
}
