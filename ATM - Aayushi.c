#include<stdio.h>
int iCardNo=1234, iPinNo=7654,a,b,i,j,flag=0;
unsigned long amount=1000, deposit, withdraw;
int choice, pin, l;
int transaction;

void operations();
int main()
{
    printf("WELCOME TO ABC SERVICES\n");
    printf("Enter your card number\n");
    scanf("%d",&a);
    if(iCardNo==a)
    {
        printf("You can proceed\n");
        flag=1;
    }
    else
    {
        printf("Your account dosen't exist\n");
    }
    if(flag==1)
    {
        for(j=3; j>=1; j--)
        {
            printf("Enter your pin number\n");
            scanf("%d",&b);
            if(iPinNo==b)
            {
                printf("Welcome to ABC services\n");
                flag=3;
                j=0;
                operations();
                for(l=4; l>=1; l--)
                {
                    printf("Do you want to have another transaction?\n  1.Yes\n  2.No\n");
                    scanf("%d", &transaction);
                    if (transaction == 0)
                    {
                        l=0;
                    }
                    else
                    {
                        operations();
                    }
                }
            }
            else
            {
                printf(" %i try left\n",j-1);
                flag=4;
            }
        }
        if (flag==4)
        {
            printf("Sorry You have entered 3 times wrong password\n");
        }
    }

}

void operations()
{
    printf("************ Welcome to ATM Service **************\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Cash\n");
    printf("3. Deposit Cash\n");
    printf("4. Quit\n");
    printf("**************************************************\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\n YOUR BALANCE IN Rs : %lu ", amount);
        break;
    case 2:
        printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
        scanf("%lu", &withdraw);
        if (withdraw % 100 != 0)
        {
            printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
        }
        else if (withdraw >(amount - 500))
        {
            printf("\n INSUFFICENT BALANCE");
        }
        else
        {
            amount = amount - withdraw;
            printf("\n\n PLEASE COLLECT CASH");
            printf("\n YOUR CURRENT BALANCE IS%lu", amount);
        }
        break;
    case 3:
        printf("\n ENTER THE AMOUNT TO DEPOSIT");
        scanf("%lu", &deposit);
        amount = amount + deposit;
        printf("YOUR BALANCE IS %lu", amount);
        break;
    case 4:
        printf("\n THANK U USING ATM");
        break;
    default:
        printf("\n INVALID CHOICE");
    }
}
