//********************************************************
// continuity.c
// Author: Lorenzo Wyman
// UCFID: 5464079
// Date: 9/19/24
// Class: COP 3223, Professor Parra
// Purpose: This program prints a specific message to the
// command line. The main purpose of this assignment is to
// ask users for input and determine the amount of items they can afford,
// calculate a numerical grade, or send emails.
// Output: (to the command line) A prompt dependant on the process that
// the user is currently utilizing.
// //********************************************************

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


//********************************************************
// int calculateUserItems(int maximumLimit)
//
// Purpose:         Calculate the amount of items that can
//                  be afforded by the user.
// Output:          There is no direct output to the terminal.
//                  it is called for in another function.
// Precondition:    The initial itemCost value is $2.
// Postcondition:   None.
//********************************************************
int calculateUserItems(int maximumLimit) {

    int totalCost = 0;
    int itemCost = 2;
    int itemCount = 0;

    // Loop to calculate how many items can be afforded
    while (totalCost + itemCost <= maximumLimit) {

        totalCost += itemCost;  // Add the current item cost to the total cost

        // If the item count is divisible by 3, apply the 66% discount
        if (totalCost % 3 == 0) {
            totalCost += (int)(totalCost * 0.34);  // Apply 66% discount
        } else {
            totalCost += itemCost;  
        }
        itemCount++;  // Increment the item count

    }

    return itemCount;

}

//********************************************************
// int determineMaxItems()
//
// Purpose:         Determine the price of the items and apply
//                  discounts if the price is divisible by 3.
//                  It also makes sure the user enters a number
//                  so that the program runs properly.
// Output:          Prints initial prompts and itemized list of 
//                  what user can afford. But not directly.
// Precondition:    The first item starts at 2$.
// Postcondition:   None.
//********************************************************
int determineMaxItems(int maximumLimit){

    int amountOfItems;
    int maxItems;
    int currentItemCost = 2;  // First item starts at $2

    // Ask user for the maximum amount of money they wish to spend
    // the "while" checks to make sure the user is inputting a number to prevent the program from continuously running.
    
    printf("\nEnter the maximum amount of money you wish to spend: $ ");

    while (scanf("%d", &maximumLimit) != 1){
       printf("Invalid input. Please enter a valid integer.");
    }

    // Determine how many items can be afforded

        maxItems = calculateUserItems(maximumLimit);
    
        printf("\nI can only afford 6 items\n", maxItems);

    // Loop that displays the cost of each item and then increments.
    
    for (amountOfItems = 1; amountOfItems <= maxItems; amountOfItems++) {
        
        // Apply the 66% discount if item is divisible by 3 (like $3, $6 and so on.)
        
        if (currentItemCost % 3 == 0) {
            printf("Item %d: $%.2f (66%% discount applied)\n", amountOfItems,currentItemCost * 0.34);

        } else {

            printf("Item %d: $%d\n", amountOfItems, currentItemCost);
        }

        // Increment the cost for the next item
        
        currentItemCost++;

    }
        return 3; // difficulty level of function
}

//********************************************************
// void outputProcessGrade (double calculateGrade)
//
// Purpose:         Outputs the appropiate numerical value based
//                  on the number calculated in the determineNumericalGrade() 
//                  function.
// Output:          this function does not print but is called on.
// Precondition:    Needs to be declared and made before the deterineNumericalGrade() function.
// Postcondition:   No return value; should appropiatley output the value based on range of calculated
//                  grade.
//********************************************************
char outputProcessGrade(double calculatedGrade){

    if (calculatedGrade >= 90 && calculatedGrade <= 100){
            printf("Your grade based on %.2lf will be 'A'", calculatedGrade);


        } else if (calculatedGrade >= 80 && calculatedGrade < 90){
            printf("Your grade based on %.2lf will be B", calculatedGrade);


        } else if (calculatedGrade >= 70 && calculatedGrade < 80){
            printf("Your grade based on %.2lf will be 'C'", calculatedGrade);


        } else if (calculatedGrade >= 60 && calculatedGrade < 70){
            printf("Your grade based on %.2lf will be 'D'", calculatedGrade);


        } else if (calculatedGrade >= 50 && calculatedGrade < 60){
            printf("Your grade based on %.2lf will be 'F'", calculatedGrade);


        } else if (calculatedGrade < 50){
            printf("Your grade based on %.2lf will be 'F'\n", calculatedGrade);

    }
    
}

//********************************************************
// int determineNumericalGrade()
//
// Purpose:         Determine and calculate the numerical grade
//                  of the user based on the 8 inputted values.
// Output:          Prints the promps for the user to enter their
//                  item grades. then prints the numerical grade.
// Precondition:    The outputProcessGrade() fucntion needs to be called at the end,
//                  but declared before this one so it actually runs without error.
// Postcondition:   A return value demonstrating the difficulty of creating this function.
//********************************************************
int determineNumericalGrade(){
    
    // item 1 - 3 = 10% of the student grade
    // item 4 & 5 = 20% of the student grade
    // item 6 & 7 are worth 5% of the student grade
    // item 8 = whatever damage is left over of the student grade (its gonna be 20% of the student grade))
    
    double item1; 
    double item2; 
    double item3; 
    double item4; 
    double item5; 
    double item6; 
    double item7; 
    double item8;
    double calculatedGrade;

    printf("-------------------------------------------\n");
    printf("Enter the grade value of the 1st item: ");
    scanf("%lf", &item1);
    printf("Enter the grade value of the 2nd item: ");
    scanf("%lf", &item2);
    printf("Enter the grade value of the 3rd item: ");
    scanf("%lf", &item3);
    printf("Enter the grade value of the 4th item: ");
    scanf("%lf", &item4);
    printf("Enter the grade value of the 5th item: ");
    scanf("%lf", &item5);
    printf("Enter the grade value of the 6th item: ");
    scanf("%lf", &item6);
    printf("Enter the grade value of the 7th item: ");
    scanf("%lf", &item7);
    printf("Enter the grade value of the 8th item: ");
    scanf("%lf", &item8);

    calculatedGrade = (item1 + item2 + item3) * 0.1 + (item4 + item5) * 0.2 + (item6 + item7) * 0.05 + (item8) * 0.2;

    printf("\nThe weighted average based on the entered values is %.2lf\n", calculatedGrade);

    outputProcessGrade(calculatedGrade);
    
    return 2; //Difficulty level of function
}


//********************************************************
// void sendEmails(int daysLeft, int hoursleft)
//
// Purpose:         To send emails from the user and not output
//                  if the remaining time is under 24 hours.
// Output:          Prints the remaining time they have remaining
//                  before the deadline.
// Precondition:    The user needs to input a hoursLeft value >= 24. 
// Postcondition:   None.
//********************************************************
void sendEmails(int daysLeft, int hoursLeft){
    
    printf("-------------------------------------------\n");
    printf("\nEnter the number of days and hours left: ");
    scanf("%d %d", &daysLeft, &hoursLeft);
    
    int dayLength = 24;
    int hoursRemaining = (daysLeft * dayLength) + (dayLength - hoursLeft);
    
    bool messagePrinted = false;  // Flag to track if the message has been printed
    
    do {
        if(hoursRemaining >= 24){
        
            printf("\nSent an email with %d hours remaining.\n", hoursRemaining);
            printf("%d will be the calculated hours left before the deadline\n" , hoursRemaining);
            printf("----------------------------------------------------------");
            messagePrinted = 1;
        } else {
            break;
        } hoursRemaining -=24; // this ensures that the print statement only prints once and not multiple times.
    } while (hoursRemaining > 0 && !messagePrinted);
        
     
        
}
     
//********************************************************
// int main(int argc, char *argv)
//
// Purpose:         Calls the functions in the order that they
//                  are needed to run the program. While doing 
//                  so continuously.
// Output:          There is no output.
// Precondition:    All of the functions need to be properly declared
//                  and called.
// Postcondition:   Return 0 if the program was successfully run.
//********************************************************
int main(int argc, char **argv) {    

    int userInput;
    int maximumLimit; 
    int daysLeft;
    int hoursLeft;
    int userSelect;

    while (1){

        printf("----------------------------\n");
        printf("What would you like to do? \n");
        printf("1. Determine Maximum Items able to Afford.\n");
        printf("2. Determine Numerical Grade.\n");
        printf("3. Send Emails.\n");
        printf("4. Exit Program.\n");
        printf("----------------------------\n");
        scanf("%d", &userSelect);
    
        if (userSelect == 1){
            determineMaxItems(maximumLimit);

        } else if (userSelect == 2){
            determineNumericalGrade();

        } else if (userSelect == 3){
            sendEmails(daysLeft, hoursLeft);

        } else if (userSelect == 4){
            break;

        } else {
            printf("Invalid option. Please try again.\n");
        }
        
    }

    return 0;
    
}