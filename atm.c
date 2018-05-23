//
//  main.c
//  Simple ATM Machine
//
//  Created by Harpreet Singh on 14/02/18.
//  Copyright © 2018 Harpreet Singh. All rights reserved.
//  

#include <stdio.h>

//Database
int CardNum[10] = {1111, 2222, 3333, 4444};
int PIN[10] = {1234, 2345, 3456, 4567};
long Balance[10] = {10000, 5000, 2000, 12500};
char Name[10][20] = {"Alpha", "Beta", "Charlie", "Delta"};

// To check Balance
void checkBalance(int account) {
    
    printf("\nYour Balance is %li \n", Balance[account]);
}

// To withdraw Cash
void withdrawCash(int account) {
    
    long amount;
    printf("\nEnter the amount to be withdrawn: ");
    scanf("%li", &amount);
    
    if ((amount % 100) != 0) {
        printf("Please enter amount in multiples of 100.\nPlease try again...\n");
        withdrawCash(account);
    }
    else if(amount > Balance[account]-100) {
        printf("Insufficiant Balance.\nPlease try again...\n");
        withdrawCash(account);
    }
    else {
        Balance[account] -= amount;
        printf("\n\nPlease collect your cash.\n");
        printf("Your updated balance is Rs. %li.\n", Balance[account]);
        
    }
}


// To deposit Cash
void depositCash(int account) {
    
    long amount;
    printf("\nEnter the amount to deposit: ");
    scanf("%li", &amount);
    
    Balance[account] += amount;
    printf("You have deposited Rs. %li\n", amount);
    printf("Your updated balance is Rs. %li.\n", Balance[account]);
}

// To update PIN
void updatePIN(int account) {
    
    int current,  new, confirm;
    printf("\nEnter your current PIN: ");
    scanf("%d", &current);
    
    if (current == PIN[account]) {
        printf("Enter your new PIN: ");
        scanf("%d", &new);
        printf("Re-enter new PIN to confirm: ");
        scanf("%d", &confirm);
        
        if (new == confirm) {
            PIN[account] = new;
            printf("Your PIN has been updated.\n\n");
        }
        else{
            printf("PIN's does not match.\nTry again...\n\n");
            updatePIN(account);
        }
    }
    else{
        printf("Entered PIN does not match.\nTry again...\n\n");
        updatePIN(account);
    }
}

int toContinue(){
    char ch;
    printf("Do you want to continue? (Y/N)");
    scanf("%ch", &ch);
    
    if (ch=='Y' || ch=='y') {
        printf("Re-Enter your PIN to continue.\n");
        return 1;
    }
    else {
        printf("You have been successfully logged out.\n\n");
        return 0;
    }
}

int main() {
    
    int account, card, pin, tries, cases;
    
    while (1) {
        printf("Welcome to the ATM Services\n");
        printf("Please enter your card number: ");
        scanf("%d", &card);
        account = -1; // Reset account value
        
        // To check Card number
        for (int i=0; i<4; ++i) {
            if (CardNum[i] == card) {
                // Card found
                account = i;
            }
        }
        
        if (account >= 0) {
            printf("\nWelcome %s\n", Name[account]);
            
            tries=3;
            while (tries>0) {
                // To verify PIN
                printf("Enter your PIN: ");
                scanf("%d", &pin);
                if (pin == PIN[account]) {
                    // PIN verified
                    tries=3;
                    printf("\nWelcome %s\n", Name[account]);
                    
                    do {
                        printf("\nEnter 1 for Balance Check.\n");
                        printf("Enter 2 for Cash Withdrawl.\n");
                        printf("Enter 3 for Cash Deposit.\n");
                        printf("Enter 4 for Update PIN.\n");
                        printf("Enter 5 for EXIT.\n");
                        printf("Enter your choice: ");
                        scanf("%d", &cases);
                        
                        switch (cases) {
                            case 1:
                                checkBalance(account);
                                break;
                            case 2:
                                withdrawCash(account);
                                printf("\nRe-Enter your PIN to continue.\n");
                                cases=0;
                                break;
                            case 3:
                                depositCash(account);
                                break;
                            case 4:
                                updatePIN(account);
                                printf("\nRe-Enter your PIN to continue.\n");
                                cases=0;
                                break;
                            case 5:
                                printf("\n\nThank you for using our ATM Services.\n");
                                printf("You have been successfully logged out.\n\n");
                                cases=0; tries=0;
                                break;
                                
                            default:
                                printf("Incorrect input. Try again...\n\n");
                                break;
                        }
                    } while (cases>0);
                }
                else{
                    // PIN incorrect
                    tries--;
                    if (tries == 0) {
                        printf("Limit exceeded. You have been logged out.\n\n");
                    }
                    else{
                        printf("Incorrect PIN. %d attempt(s) left.\n\n", tries);
                    }
                }
            }
        }
        else{
            // Card does not exist
            printf("Card not found. Try again\n\n");
        }
        
    }
    
    
    return 0;
}







