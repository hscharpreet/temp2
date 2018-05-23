
#include <stdio.h>
#include <stdlib.h>

// Database
int choice,tries=3,cardno1,pin1,deposit, withdraw,count,a,flag;
int cardno[3]= {1000,2000,3000};
int pin[3]= {100,200,300};
int balance[3]= {10000,20000,30000};
char person[10][10]= {"Harpreet","Gurpreet","Emon"};

// Main Program
int main() {
    do {
        printf("\nEnter your card no.\n");
        scanf("%d",&cardno1);
        for(int i=0; i<3; i++){
            if(cardno[i]==cardno1) {
                while(tries!=0) {
                    printf("Enter your pin\n");
                    scanf("%d",&pin1);
                    if(pin[i]==pin1){
                        flag=1;
                        break;
                    }
                    else {
                        tries--;
                        printf("You have entered wrong pin\n");
                        printf("No. of tries left %d\n",tries);
                        flag=0;
                    }
                }
                if(flag==1) { 
                    printf("Welcome %s\n",person[i]);
                    printf("1. Check Balance\n");
                    printf("2. Withdraw Cash\n");
                    printf("3. Deposit Cash\n");
                    printf("4. Quit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    if(choice==1) {
                        // Check Balance
                        printf("\nYOUR BALANCE IN Rs : %d ", balance[i]);
                        continue;
                    }
                    else if(choice==2) {
                        // Withdraw Cash
                        printf("\nENTER THE AMOUNT TO WITHDRAW: ");
                        scanf("%d", &withdraw);
                        if (withdraw % 100 != 0){
                            printf("\nPLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
                        }
                        else if (withdraw >(balance[i] - 500)){
                            printf("\nINSUFFICENT BALANCE");
                        }
                        else{
                            balance[i] = balance[i] - withdraw;
                            printf("\n\nPLEASE COLLECT CASH");
                            printf("\nYOUR CURRENT BALANCE IS%d\n",balance[i]);
                        }
                        continue;
                    }
                    else if(choice==3) {
                        // Deposit Cash
                        printf("\nENTER THE AMOUNT TO DEPOSIT");
                        scanf("%d", &deposit);
                        balance[i] = balance[i] + deposit;
                        printf("YOUR BALANCE IS %d\n", balance[i]);
                        continue;
                    }
                    else  if(choice==4) {
                        // Exit
                        printf("\nTHANK U USING ATM\n");
                    }
                    else {
                        printf("\nINVALID CHOICE");
                    }
                }//end of pin if statement
            }//End of Card IF
            else {
                continue;
            }
        }//end of for statement
        tries=3;
    } while(1);
    return 0;
}
