
#include<stdio.h>
#include<stdlib.h>
// DataBase declaration and Definition
char user_list[4][15]= {"Mr. Akshay","Mr. Pardeep","Mr. Jaideep","Mr. Manager"};
int index,pin, pass,ch,user, pin1=144,pin2=133,pin3=122,user1=1234,user2=5678,user3=9012;
unsigned long int Amount,Total_cash=100000, Amount1=1000,Amount2=2000,Amount3=3000;
//Function to Display Choice Screen
int CHOICE()
{   int choice;
    printf("\n1:BALANCE INQUIRY \t\t2:CASH WITHDRAW \n3:DEPOSIT MONEY\t\t\t4:CANCEL\n");
    printf( "\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}
// Main Function
int main()
{
    do
    {
        printf("\n\n\t\tWELCOME TO BANK OF CGC\n\n");
        printf("Enter Your Card:");
        scanf("%d",&user);
        printf("Enter your 3 digit security PIN:");
        scanf("%d",&pin);
        if(user == user1)
        {   
            index=0;
            Amount=Amount1; // if User1 Enters
        }
        else if(user == user2)
        {   
            index=1;
            Amount =Amount2; //if user2 Enters
        }
        else if (user == user3)
        {   
            index=2;
            Amount =Amount3; //if user3 Enters
        }
        else
        {   
            index =3; // To diplay Manager
        }
        if ( ( user == user1 && pin == pin1 ) || (user ==user2 && pin==pin2) || (user ==user3 && pin==pin3) ) //If any of the user Enters his/her details correctly
        {   
            printf(" \n\n\t\tWELCOME %s \n\n",user_list[index]);  // Display Welcome Username
            ch = CHOICE();
            if (ch == 1)  // Balance Enquiry
            {   if(Amount==0) //if User Have 0 Account Balance
                {   
                    printf("Sorry! You Have 0 Account Balance\nPress anykey to Continue");
                    continue;
                }
                // Display Account Balance
                else
                {   
                    printf("Your Account Balance is %ld", Amount);
                    printf("\nPress anykey to Continue");
                    continue;
                }
            }
            else if (ch == 2)   // Withdraw
            {   
                unsigned long int amt;
                printf("Enter Amount you Want to Withdraw: ");
                scanf("%ld",&amt);
                if( amt % 100 != 0)// if Withdraw Amount is Multiple of 100
                {
                    printf("Enter withdraw Amount in Multiple of 100\npress anykey to continue");
                    continue;
                }
                else if(amt > Amount)    // if Withdraw Amount is more than Account Balance
                {   if(amt > Total_cash)  // if withdrwa Amount is more than Cash Available in ATM (100000)
                    {   
                        printf("Cash Not Available\nplease visit nearby ATM");
                        continue;
                    }
                    else
                    {   
                        printf("You have Insufficient Balance\nPress anykey to continue");
                        continue;
                    }
                }
                else if (  (amt<= Amount) && ( amt < Total_cash) && (amt > 100) && (amt < 40000) ) // Security Check
                {   
                    printf( "\nYour Transcation is being Processed\n\nPlease Collect Your CASH ");
                    Amount = Amount - amt;
                    Total_cash=Total_cash-amt;
                    if(user ==user1 && pin == pin1)  // To Update Balance in Database
                    {
                        Amount1=Amount;
                    }
                    else if(user ==user2 && pin==pin2)
                    {
                        Amount2=Amount;
                    }
                    else if (user == user3 && pin==pin3 )
                    {
                        Amount3 =Amount;
                    }
                    printf("\nYour Updated Balance is %lu", Amount);
                    printf("\nPress anykey to EXIT");
                    continue;
                }
                else // Withdraw Amount Exceeds 40000
                {
                    printf("Withdraw Limit Exceeds \nPress anykey to continue ");
                    continue;
                }
            } // Cancel
            else if (ch == 4)
            {   
                continue;
            }
            else if(ch==3) // Deposit Money
            {   
                unsigned long int Deposit_amount;
                printf("Deposit Money:");
                scanf("%ld",&Deposit_amount); // Enter Money to be Deposited
                
                if(Deposit_amount%100!=0)
                {   
                    printf("Deposit Amount must be multiple of 100\nPress any key to continue..."); // Checks Deposit Money Multiple of 100
                    continue;
                }
                else
                {   
                    Amount=Amount+Deposit_amount;
                    if(user ==user1 && pin == pin1)  // To Update Balance in Database
                    {
                        Amount1=Amount;
                    }
                    else if(user ==user2 && pin==pin2)
                    {
                        Amount2=Amount;
                    }
                    else if (user == user3 && pin==pin3 )
                    {
                        Amount3 =Amount;
                    }
                    printf("\nYour Updated Balance is %ld ",Amount);
                    printf("\nPress anykey to Continue...");
                    continue;
                }
            }
            else
            {   
                printf("Please Enter Some valid choice\nPress anykey to get started again");
                continue;
            }
        }
        else if(user == 1111 && pin == 1111) // Manager
        {   
            printf("Welcome %s",user_list[index]);
            printf("\nEnter Password:");  // Password to SHUTDOWN Machine (204)
            scanf("%d",&pass);
            if(pass==204)
            {   
                printf("Machine Shutting Down....");
                printf("\nPress anykey");
                exit(0);
            }
        }
        else if ( (user ==user1 && pin!=pin1) || (user ==user2 && pin!=pin2 ) || (user == user3 && pin!=pin3)  ) // If User Enters Incorrect PIN
        {   
            printf("You PIN is Incorrect\nPress anykey to continue");
            continue;
        }
        else if(  user != user1 || user !=user2 || user !=user3 )  // if Card is not properly Inserted
        {   
            printf("You Card is not properly inserted \nPress anykey to continue");
            continue;
        }
        else // If user Input Some Invalid Data
        {
            printf("Something Wrong has Happened\nPlease Try Again\nPress anykey to Continue");
        }
    } while (1);
}
