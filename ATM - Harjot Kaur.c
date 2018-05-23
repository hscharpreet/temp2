#include<stdio.h>
#include<stdlib.h>
int balance1;
int main()
{
    int password;
    int pincode;
    if(pincode==1111) {
        password=5555;
    }
    else if(pincode==2222) {
        password=6666;
    }
    for(int i=1; i<=10; i++)
    {
        if(i==2||i==3||i==4 || i==5 || i==6 || i==7 || i==8 || i==9 || i==10)
        {
            printf("\n\n Welcome Again \n\t\t\t\tMain Page\n");
        }
        system("cls");
        printf("Please Enter The Pincode\n");
        scanf("%d",&pincode);
        system("cls");
        if(pincode == 1111)
        {   system("cls");
            printf("Welcome Harjot\n");
            for (int i=0; i<3; i++)
            {
                printf("Enter Password: ");
                scanf("%d",&password);
                system("cls");
                int balance = 10000;
                balance1=balance;
                if (password==5555)
                {
                    for(int i=1; i<=10; i++)

                    {
                        int option, withdraw, deposit;
                        printf("\n");
                        if(i==1)
                        {
                            printf("Please Select\n");
                        }
                        printf("[1] Inquire Balance \n");
                        printf("[2] Withdraw \n");
                        printf("[3] Deposit \n");
                        printf("[4] Quit \n ");
                        printf("\n ");
                        printf("Enter Option ");
                        scanf("%d", &option);
                        system("cls");
                        switch(option)
                        {
                        case 1:
                            printf("\n BALANCE INQUIRY");
                            printf("\n Your Current Balance is Rs. %d",balance1);
                            printf("\n");
                            continue;
                        case 2:
                            printf("Withdraw\n");
                            printf("Enter Amount In Rupees: ");
                            scanf("%d",&withdraw);
                            balance1=balance1-withdraw;
                            printf("You withdrew Rs. %d", withdraw);
                            printf("\n");
                            printf("\nYour New Balance Is%d",balance1);
                            printf("\n");
                            continue;
                        case 3:
                            printf("Deposit\n");
                            printf("Enter Amount in Rs.\n");
                            scanf("%d",&deposit);
                            balance1=balance1+deposit;
                            printf("You Deposited Rs.%d",deposit);
                            printf("\n");
                            printf("Your New Balance is Rs.%d",balance1);
                            printf("\n");
                            continue;
                        case 4:
                            printf("Exit");
                            break;
                        default:
                            printf("That is an invalid option please enter correct option");
                            continue;
                        }
                        break;


                    }
                    break;
                }
                else if(i==2)
                {   printf("\nCard is Captured\n");
                }
                else
                    printf("Please Try Again!!!\n");
            }
        }
        if(pincode==2222)
        {
            printf("Welcome Harpreet\n");
            for(int i=0; i<3; i++)
            {
                printf("Enter Password: ");
                scanf("%d",&password);
                system("cls");
                int balance = 52000;
                balance1=balance;
                if (password==6666)
                {
                    for(int i=1; i<=10; i++)
                    {
                        int option,withdraw, deposit;
                        {
                            printf("\n");
                            if(i==1)
                            {
                                printf("Please Select\n");
                                printf("\n");

                            }
                            printf("Please Select\n");
                            printf("[1]Inquire Balance\n");
                            printf("[2]Withdraw\n");
                            printf("[3]Deposit\n");
                            printf("[4]Quit\n");

                            printf("\n");
                            printf("Enter Option");
                            scanf("%d",&option);
                            system("cls");
                            switch(option)
                            {
                            case 1:
                                printf("\n BALANCE INQUIRY");
                                printf("\n Your Current Balance is Rs. %d",balance);
                                printf("\n");
                                continue;
                            case 2:
                                printf("Withdraw");
                                printf("Enter Amount In Rupees:");
                                scanf("%d", &withdraw);
                                balance1=balance1-withdraw;
                                printf("You withdrew Rs. %d",withdraw);
                                printf("\n");
                                printf("\nYour New Balance Is %d",balance1);
                                printf("\n");
                                continue;
                            case 3:
                                printf("Deposit\n");
                                printf("Enter Amount in Rs.\n");
                                scanf("%d",&deposit);
                                balance1=balance1+deposit;
                                printf("You Deposited Rs.%d",deposit);
                                printf("\n");
                                printf("Your New Balance is Rs. %d",balance1);
                                printf("\n");
                                continue;
                            case 4:
                                printf("Exit");
                                break;
                            default:
                                printf("That is an invalid option please enter correct option");
                                continue;
                            }
                            break;


                        }
                        break;
                    }
                    return 0;
                }
            }
        }
    }
}
