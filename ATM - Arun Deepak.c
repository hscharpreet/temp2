#include <stdio.h>
#include<string.h>

struct persons {
    long int amount;
    char name[20];
    int pin;
    int card_no;
};

int scanf_card_no;
int scanf_pin;
int withdraw;
int choice;
int k;
char transaction ='y';

int main()
{   int i;

    struct persons *personptr,person1,person2,person3;

    person1.card_no=1465;
    strcpy(person1.name,"Mr. Akash");
    person1.pin=1654;
    person1.amount=2000;

    person2.card_no=5468;
    strcpy(person2.name,"Mr. Vivek");
    person2.pin=3064;
    person2.amount=5000;

    person3.card_no=4682;
    strcpy(person3.name,"Mrs. Miranda");
    person3.pin=4561;
    person3.amount=6000;

label:
    do
    {
        printf("********Welcome to ATM Service**************\n");
        printf("Enter your card no\n");
        scanf("%d\n",&scanf_card_no);
        printf("\n");

        if(person1.card_no==scanf_card_no)
        {
            personptr=&person1;
        }
        else
        {   if(person2.card_no==scanf_card_no)
            {
                personptr=&person2;
            }
            else
            {   if(person3.card_no==scanf_card_no)
                {
                    personptr=&person3;
                }
            }
        }

        if(scanf_card_no!=(person1.card_no||person2.card_no||person3.card_no))
        {
            printf("Invalid Card No.\n");
            printf("Retry\n");
        }
        printf("*********************************************\n\n\n");
    }
    while (scanf_card_no!=(person1.card_no|person2.card_no|person3.card_no));

xyz:
    for(i=3; i<=1; i--)
    {
        printf("********Welcome to ATM Service**************\n");
        printf("%s%s","Hello",(*personptr).name);
        printf("Enter ATM PIN\n");
        scanf("%d",&scanf_pin);
        printf("/n");

        if(scanf_pin!=(person1.pin||person2.pin||person3.pin))
        {
            printf("Invalid Pin.\n");
            printf("%s%d%s","Retry(Only\t",--i,"\tmore attempt left\n");
        }

        if(i==1)
        {   fflush(stdin);
            goto label;
        }

        printf("***********************************************\n\n\n");
    }

    do
    {
        printf("********Welcome to ATM Service**************\n");
        printf("\t\tSelect a transaction\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Quit\n");
        printf("***********************************************\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n YOUR BALANCE IN Rs : %lu ",(*personptr).amount);
            break;
        case 2:
            printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
            scanf("%d",&withdraw);
            if (withdraw%100!=0)
            {
                printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
            }
            else if (withdraw >(*personptr).amount)
            {
                printf("\n INSUFFICENT BALANCE");
            }
            else
            {
                (*personptr).amount=(*personptr).amount-withdraw;
                printf("\n\n PLEASE COLLECT CASH");
                printf("\n YOUR CURRENT BALANCE IS%lu",(*personptr).amount);
            }
            break;
        case 3:
            printf("\n THANK YOU FOR USING ATM");
            break;
        default:
            printf("\n INVALID CHOICE");
        }
        printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
        fflush(stdin);

        if(transaction =='y'||transaction =='Y')
        {   fflush(stdin);
            goto xyz;
        }

        scanf("%c", &transaction);
        if (transaction == 'n'|| transaction == 'N')
            k = 1;
    } while (!k);
    printf("\n\n THANKS FOR USING OUT ATM SERVICE");
}