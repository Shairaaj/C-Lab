#include<stdio.h>
#define MAX 10
struct customer{
    int accNo;
    char name[20];
    char address[20];
    char dob[10];
    int balance;
};

void createCustomer();
void balanceEnq();
void amountDeposit();
void withdrawAmount();

typedef struct customer Customer;

Customer arr[MAX];

void main(){
    int ch = 1;
    int curr = -1;

    while(ch != 0){
        printf("Enter\n 0->EXIT\n 1->Create Customer\n 2->Balance Enquiry\n 3->Amount Deposit\n 4->Withdraw Amount\n");
        printf("Enter the choice: \n");
        int success = scanf("%d", &ch);
        if(success != 1){
            printf("Enter a number\n");
            return;
        }
        switch(ch){
            case 0:
                return;
            case 1:
                createCustomer(&curr);
                break;
            case 2:
                balanceEnq(&curr);
                break;
            case 3:
                amountDeposit(&curr);
                break;
            case 4:
                withdrawAmount(&curr);
                break;
            default:
                printf("Enter the valid input\n");
                break;
        }
    }
}

void createCustomer(int *curr1){
    ++(*curr1);
    printf("Enter the account number:\n");
    scanf("%d", &(arr[*curr1].accNo));
    printf("Enter the name:\n");
    scanf("%s", (arr[*curr1].name));
    printf("Enter the Date of Birth:\n");
    scanf("%s", (arr[*curr1].dob));
    printf("Enter the address:\n");
    scanf("%s", (arr[*curr1].address));
    printf("Enter the balance:\n");
    scanf("%d", &(arr[*curr1].balance));

    printf("The inserted values are: \n");
    printf("The account number: %d\n",arr[*curr1].accNo);
    printf("The name is: %s\n",arr[*curr1].name);
    printf("The dob is: %s\n",arr[*curr1].dob);
    printf("The address: %s\n",arr[*curr1].address);
    printf("The current balance: %d\n",arr[*curr1].balance);

}

void balanceEnq(int *curr1){
    int fAccNo= 0;
    printf("Enter the account number: \n");
    scanf("%d",&fAccNo);
    printf("The account number to search is: %d\n", fAccNo);
    for(int i=0; i<=(*curr1); i++){
        if(arr[i].accNo == fAccNo){
            printf("The account number: %d\n",arr[i].accNo);
            printf("The name is: %s\n",arr[i].name);
            printf("The dob is: %s\n",arr[i].dob);
            printf("The address: %s\n",arr[i].address);
            printf("The current balance: %d\n",arr[i].balance);
            return;
        }
    }
    printf("Account number not found!\n");
}

void amountDeposit(int *curr1){
    int fAccNo= 0;
    int amount;
    printf("Enter the account number: \n");
    scanf("%d",&fAccNo);
    printf("Enter the amount to deposit:\n");
    scanf("%d",&amount);
    for(int i=0; i<=(*curr1); i++){
        if(arr[i].accNo == fAccNo){
            arr[i].balance += amount;
            printf("The current balance is: %d\n", arr[i].balance);
            return;
        }
    }
    printf("Account number not found!\n");
}

void withdrawAmount(int *curr1){
    int fAccNo= 0;
    int amount;
    printf("Enter the account number: \n");
    scanf("%d",&fAccNo);
    printf("Enter the amount to withdraw:\n");
    scanf("%d",&amount);
    for(int i=0; i<=(*curr1); i++){
        if(arr[i].accNo == fAccNo){
            if(arr[i].balance-amount<500){
                printf("Should maintain >500rs\n");
                return;
            }
            arr[i].balance -= amount;
            printf("The current balance is: %d\n", arr[i].balance);
            return;
        }
    }
    printf("Account number not found!\n");
}