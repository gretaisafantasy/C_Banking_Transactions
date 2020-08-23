/* ------------------------------------------------------------------------------------
Program file: banking_transactions.c
Author: Greta Tanudjaja
Date: April 5, 2020
Assignment: #5
Objective: This program calculates the ending/closing balance of banking transactions.
The result of the calculation and the bank record is then output. User input of the 
current balance, the number and amounts of deposits and withdrawals is required.
------------------------------------------------------------------------------------ */

#include <stdio.h>

/* Function Prototypes */
/* ------------------- */

int get_deposit_number (int);
int get_withdrawal_number (int);
float get_beginning_balance (float);
float get_deposit_amount (int, float []);
float get_balance (float, float);
float get_withdrawal_amount (int, float [], float);
float get_closing_balance (float, float);
void get_bank_record (float, int, float [], int, float [], float);

/* Begin main */
/* ---------- */

int main(void)
{
    
    /* Declare variables */
    /* ----------------- */
    
    int deposit_number, deposit, withdrawal_number, withdrawal;
	float deposits[5] = {0};
 	float withdrawals[5] = {0};
	float beginning_balance, beginning, balance, closing_balance;
	float deposit_amount = 0.0;
	float withdrawal_amount = 0.0;
                                    
    /* Display the initial greeting */
    /* ---------------------------- */
    
    printf("Welcome to the Computer Banking System\n");
    
    /* Call function to get current balance in dollars and cents */                  
    /* --------------------------------------------------------- */ 
    
    beginning_balance = get_beginning_balance (beginning);
    
    /* Call function to get number of deposits */                  
    /* --------------------------------------- */
    
    deposit_number = get_deposit_number (deposit);
    
    /* Call function to get number of withdrawals */                  
    /* ------------------------------------------ */
    
    withdrawal_number = get_withdrawal_number (withdrawal);
    
    /* Call function to get total amount of deposits */                  
    /* --------------------------------------------- */
    
    deposit_amount = get_deposit_amount (deposit_number, deposits); 
    
    /* Call function to get balance so far */
    /* ----------------------------------- */ 
    
	balance = get_balance (beginning_balance, deposit_amount);
    
    /* Call function to get total amount of withdrawals */                  
    /* ------------------------------------------------ */
    
    withdrawal_amount = get_withdrawal_amount (withdrawal_number, withdrawals, balance);
    
    /* Call function to get closing balance */                  
    /* ------------------------------------ */
    
 	closing_balance = get_closing_balance (balance, withdrawal_amount);
  	
 	/* Call function to get bank record */                  
    /* -------------------------------- */
    
    get_bank_record (beginning_balance, deposit_number, deposits, withdrawal_number,
    withdrawals, closing_balance);
    
    return 0;

} /* end main */
    
/* Begin function get_beginnning_balance to prompt user for current balance in dollars and cents */
/* --------------------------------------------------------------------------------------------- */

float get_beginning_balance (float beginning)
{  
    float beginning_balance;
    
  	do
    {
        printf("\nEnter your current balance in dollars and cents: ");
        scanf ("%f", &beginning_balance);
    
    /* Ensure beginning balance is a positive number. If not, issue error message and re-prompt */                          
    /* -----------------------------------------------------------------------------------------*/ 
        
        if (beginning_balance < 0)
 	  	    printf ("*** Beginning balance must be at least zero, please re-enter.");
 	  	    
    } while (beginning_balance < 0);
    
    return beginning_balance;
	 
} /* end get_beginning_balance */

/* Begin function get_deposit_amount to get the total amount of deposits */
/* ---------------------------------------------------------------------- */

int get_deposit_number (int deposit)
{
	int deposit_number;
	
 	do
    {
        printf("\nEnter the number of deposits (0 - 5): ");
        scanf ("%i", &deposit_number);
    
    /* Ensure deposit number is between 0 and 5. If not, issue error message and re-prompt */  
    /* ----------------------------------------------------------------------------------- */ 
    
        if (deposit_number < 0 || deposit_number > 5)
 	  	    printf ("*** Invalid number of deposits, please re-enter.");
 	  	    
    } while (deposit_number < 0 || deposit_number > 5);
    
    return deposit_number;
    
} /* end get_deposit_number */
	
/* Begin function get_withdrawal_number to prompt user for number of withdrawals */
/* ----------------------------------------------------------------------------- */

int get_withdrawal_number (int withdrawal)
{
	int withdrawal_number;
		
 	do
    {
        printf("\nEnter the number of withdrawals (0 - 5): ");
        scanf ("%i", &withdrawal_number);
    
    /* Ensure withdrawal number is between 0 and 5. If not, issue error message and re-prompt */                                                        
    /* -------------------------------------------------------------------------------------- */
        
        if (withdrawal_number < 0 || withdrawal_number > 5)
 	  	    printf ("*** Invalid number of withdrawals, please re-enter.");
 	  	    
    } while (withdrawal_number < 0 || withdrawal_number > 5);
    
    return withdrawal_number;
	  
} /* end get_withdrawal_number */

/* Begin function get_deposit_amount to get the total amount of deposits */
/* --------------------------------------------------------------------- */    

float get_deposit_amount (int deposit_number, float deposits[])
{
	int x;
  	float deposit_amount = 0.0;
	
	/* Prompt user for amount of deposit */                  
    /* --------------------------------- */
	
    for (x = 0; x < deposit_number; x++)
    {
        printf("\nEnter the amount of deposit #%i: ", x + 1);
        scanf ("%f", &deposits[x]);
 
    /* Ensure deposit amount is greater than 0. If not, issue error message and re-prompt */                                                        
    /* ---------------------------------------------------------------------------------- */ 
    
        if (deposits[x] < 0)
	    {
 	  	    printf ("*** Deposit amount must be greater than zero, please re-enter.");
	  	    x--;
	  	    continue;
  	    }
	    else (deposits[x] > 0);
	    
   	/* Assign a formula that will accumulate the deposit amount of all valid user inputs */
 	/* --------------------------------------------------------------------------------- */
    
        deposit_amount = deposit_amount + deposits[x];
        
    } /* end for loop */
    
    return deposit_amount;
	    
} /* end get_deposit_amount */

/* Begin function get_balance to get the balance so far */
/* ---------------------------------------------------- */

float get_balance (float beginning_balance, float deposit_amount)
{ 
    float balance;
    
	balance = beginning_balance + deposit_amount;
	
	return balance;
	
} /* end get_balance */

/* Begin function get_withdrawal_amount to get the total amount of withdrawals */
/* --------------------------------------------------------------------------- */   

float get_withdrawal_amount (int withdrawal_number, float withdrawals[], float balance)
{
	int y;
	float current_balance;
  	float withdrawal_amount = 0.0;
		         
    /* Prompt user for amount of withdrawal */                  
    /* ------------------------------------ */
    
    for (y = 0; y < withdrawal_number; y++)
	{
		printf("\nEnter the amount of withdrawal #%i: ", y + 1);
		scanf ("%f", &withdrawals[y]);
    
    /* Ensure withdrawal amount does not exceed the current balance (including the new deposits). If not, */
	/* issue error message and re-prompt 																  */                                                     
    /* -------------------------------------------------------------------------------------------------- */ 	
			
		current_balance = balance - withdrawal_amount; 
		 
 		if (withdrawals[y] < 0 || withdrawals[y] > current_balance)
  		{
   			printf ("*** Withdrawal amount exceeds current balance.");
	    	y--;
	    	continue;
   		}
 		else (withdrawals[y] > 0 || withdrawals[y] < current_balance);
	
    /* Assign a formula that will accumulate the withdrawal amount of all valid user inputs */
    /* ------------------------------------------------------------------------------------ */   
        
       	withdrawal_amount = withdrawal_amount + withdrawals[y];

	} /* end for loop */
	
	return withdrawal_amount;
	
} /* end get_withdrawal_amount */

/* Begin function get_closing_balance to get the closing balance */
/* ------------------------------------------------------------- */

float get_closing_balance (float balance, float withdrawal_amount)
{ 
    float closing_balance;
    
	closing_balance = balance - withdrawal_amount; 
	
	/* Display the closing balance */                  
  	/* --------------------------- */
        
  	printf("\n***The closing balance is $%.2f***\n", closing_balance);

	/* Based on the closing balance, output appropriate text. */
    /* ------------------------------------------------------ */
    
    if (closing_balance >= 0.00 && closing_balance <= 999.99)
	    printf ("\n*** Your balance is getting low! ***");
    else if (closing_balance >= 1000.00 && closing_balance <= 14999.99)
        printf ("\n*** Keep up the good work! ***");
    else if (closing_balance >= 15000.00 && closing_balance <= 49999.99)
        printf ("\n*** Maybe you should consider a CD. ***");
    else if (closing_balance >= 500000.00)
        printf ("\n*** It is time to invest some money! ***");
        
   	return closing_balance;
	
} /* end get_closing_balance */

/* Begin function get_bank_record to get the bank record */
/* ----------------------------------------------------- */

void get_bank_record (float beginning_balance, int deposit_number, float deposits [],
int withdrawal_number, float withdrawals [], float closing_balance)
{
    int x, y;
    
    /* Display the bank record */
    /* ----------------------- */
	    
    printf("\n\n*** Bank Record *** ");
    
    /* Display the starting balance */
    /* ---------------------------- */
    
    printf("\n\nStarting Balance:  $ %.2f\n", beginning_balance);
    
    /* Output the deposit amount */
 	/* ------------------------- */
      
 	for (x = 0; x < deposit_number ; x++)
 		printf ("\nDeposit #%i:    	     %.2f\n", x + 1, deposits[x]);
 		
   	/* Output the withdrawal amount */
 	/* ---------------------------- */
      
 	for (y = 0; y < withdrawal_number ; y++)
 		printf ("\nWithdrawal #%i: 	     %.2f\n", y + 1, withdrawals[y]);
    
    /* Display the ending balance */
    /* -------------------------- */
    
    printf("\nEnding Balance:    $ %.2f", closing_balance);

} /* end get_bank_record */
