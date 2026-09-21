/*
 * Author:  Hayden Walker
 * Program: The Corner Store Simulator
 * Purpose: Act as a register for self-checkout, allowing a customer to ring up 
            preset items for a total, as well as not accepting random incorrect 
            values.
 * Reflection:  Writing all the contingencies felt like hell. Making sure I could
                account for most if not all outcomes was exhausting,but worth it.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //First going to declare all preset variables
    //Product prices, won't ever be changed by user 
    static float applePrice = 2.50, bananaPrice = 1.20, carrotPrice = 3.00, orangePrice = 2.00; 
    //Tracking counts of each item so they can't go negative and give an incorrect price count
    int appleCount = 0, bananaCount = 0, carrotCount = 0, orangeCount = 0;
    //Background numbers
    float subTotal, finalTotal, salesTax = 8.25, discount;
    int exitCon = 0, startCon = 0;
    /*Temp variable, obvious name for purpose, put global scope to be used in
    and out of first while loop at Line 39*/
    char yorN;
    
    /*Basically this is going to have the main interface be in one big while loop, 
    where it will keep asking things like what items the user wants and how many,
    until exitCon is triggered to change.*/
    
    //First, going to start with an intro/menu screen
    printf("--------------------------------\n");
    printf("Welcome to the Tiny Cornerstore!\n");
    printf("--------------------------------\n");
    printf("Our inventory IS limited to: \nApples - $2.50 each\nBananas - $1.20 each\nCarrots - $3.00 each\nOranges - $2.00 each\n");
    //Beginning conditional to start or cancel transaction
    while(startCon == 0){
        printf("Would you like to begin your transaction? (Y/N)\n");
        scanf(" %c", &yorN);
        //Leads to starting rest of program
        if(yorN == 'y' || yorN == 'Y'){
            printf("Great! Let's get started!\n");
            startCon = 1;
        }
        //Breaks out of loop to lead to ending program(See Line 58)
        else if(yorN == 'n' || yorN == 'N'){
            printf("No problem, have a great day!");
            startCon = 1;
        }
        //Makes sure no incorrect entries are accepted and keeps loop intact
        else{
            printf("I'm sorry, please input a correct character.\n");
        }
    }
    //Fully exits the program without continuing further
    if(yorN == 'n' || yorN == 'N'){
        printf("Ok, closing program...\nHave a nice day!");
        return 0;
    }
    
    //Now for the big loop, only changed when user enters some form of "Exit"
    while(exitCon == 0){
        //Going to track which item is used
        char currentItem [10], cancelCode [10];
        //Tracks number of items rung up at once, and if the input is valid (int)
        int itemCount, realAnswer = 0;
        printf("What item are you buying; Apple(s), Banana(s), Carrot(s), or Orange(s)? \n");
        scanf("%10s", currentItem);
        /*Put in some contingencies for each, just in case. But if it's not these, 
        it SHOULD loop to asking again. Hopefully user figures it out*/
        //Apple Section
        //This checks for 6 more common results of an input. Can't account for all of them
        if(strcmp(currentItem, "Apple") == 0 || strcmp(currentItem, "apple") == 0 || 
           strcmp(currentItem, "APPLE") == 0 || strcmp(currentItem, "Apples") == 0 || 
           strcmp(currentItem, "apples") == 0 || strcmp(currentItem, "APPLES") == 0) {
            //realAnswer is only changed when a real answer is inputted. 
            while(realAnswer == 0){
                //Displays current total of items for live tracking
                printf("You have %d apples currently rung up!\n", appleCount);
                printf("How many apples are you buying?\nIf you want to remove apples from the total, input a negative number!\n");
                scanf("%d", &itemCount);
                //Assuming the user wants to add items to the total
                if(itemCount >= 1){
                    //Adds itemCount to total count of item to check if the total number of items is valid (not negative)
                    appleCount += itemCount;
                    /*If total item count is positive after the change, will add the itemCount of items to subTotal 
                    and also add them to the total count of the item from before */
                    if(appleCount >= 0){
                        printf("Ok, %d apples have been added to the total!\n", itemCount);
                        subTotal += itemCount * applePrice;
                        realAnswer = 1;
                    }
                    /*If the total count of item is now a negative number (even though it's adding), throws an invalid ERROR
                    and asks for re-input, as well as removing the itemCount from the total to not let invalid numbers through*/
                    else if(appleCount < 0){
                        printf("ERROR: Total number of apples is invalid (Negative number)!!!\nPlease try again\n");
                        appleCount -= itemCount;
                    }
                    /*If the input is some other data type it throws an ERROR and asks for re-input*/
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                    
                }
                //If the input is a negative number, the user wants to subtract items from the total count
                else if(itemCount < 0){
                    //Gets the absolute value of negative number for calculating lines
                    itemCount = abs(itemCount);
                    //Takes away the number of items wanting to be removed from the total item count
                    appleCount -= itemCount;
                    //If the total item count is still positive, then follows removal of itemCount to total count
                    if(appleCount >= 0){
                        printf("Ok, removing %d apples from the total!\n", itemCount);
                        subTotal -= itemCount * applePrice;
                        realAnswer = 1;
                    }
                    //If total count of item is invalid (negative), reverses itemCount subtraction and throws an ERROR
                    else if(appleCount < 0){
                        printf("ERROR: Total number of apples is invalid (Negative number)\nPlease try again\n");
                        appleCount += itemCount;
                    }
                    //If itemCount is an invalid input, throws an ERROR for re-input
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                }
                else {
                    //If they want to cancel the selection
                    scanf("%10s", cancelCode);
                    if(strcmp(cancelCode, "CANCEL") == 0 || strcmp(cancelCode, "cancel") == 0 || strcmp(cancelCode, "Cancel") == 0) {
                        printf("Returning to item selection...\n");
                        realAnswer = 1;
                    }
                    //Assures input entered is valid (not a float or anything else)
                    else {
                        printf("ERROR: Invalid Input!!!\nPlease input an integer value >= 1 OR enter CANCEL to exit apple selection!\n");
                    }
                }
            }
        }
        //Banana Section
        //This checks for 6 more common results of an input. Can't account for all of them
        else if(strcmp(currentItem, "Banana") == 0 || strcmp(currentItem, "banana") == 0 || 
           strcmp(currentItem, "BANANA") == 0 || strcmp(currentItem, "Bananas") == 0 || 
           strcmp(currentItem, "bananas") == 0 || strcmp(currentItem, "BANANAS") == 0) {
            //realAnswer is only changed when a real answer is inputted. 
            while(realAnswer == 0){
                //Displays current total of items for live tracking
                printf("You have %d bananas currently rung up!\n", bananaCount);
                printf("How many bananas are you buying?\nIf you want to remove bananas from the total, input a negative number!\n");
                scanf("%d", &itemCount);
                //Assuming the user wants to add items to the total
                if(itemCount >= 1){
                    //Adds itemCount to total count of item to check if the total number of items is valid (not negative)
                    bananaCount += itemCount;
                    /*If total count is positive after the change, will add the itemCount of items to subTotal 
                    and also add them to the total count of the item from before */
                    if(bananaCount >= 0){
                        printf("Ok, %d bananas have been added to the total!\n", itemCount);
                        subTotal += itemCount * bananaPrice;
                        realAnswer = 1;
                    }
                    /*If the total count of item is now a negative number (even though it's adding), throws an invalid ERROR
                    and asks for re-input, as well as removing the itemCount from the total to not let invalid numbers through*/
                    else if(bananaCount < 0){
                        printf("ERROR: Total number of bananas is invalid (Negative number)!!!\nPlease try again\n");
                        bananaCount -= itemCount;
                    }
                    /*If the input is some other data type it throws an ERROR and asks for re-input*/
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                    
                }
                //If the input is a negative number, the user wants to subtract items from the total count
                else if(itemCount < 0){
                    //Gets the absolute value of negative number for calculating lines
                    itemCount = abs(itemCount);
                    //Takes away the number of items wanting to be removed from the total item count
                    bananaCount -= itemCount;
                    //If the total item count is still positive, then follows removal of itemCount to total count
                    if(bananaCount >= 0){
                        printf("Ok, removing %d bananas from the total!\n", itemCount);
                        subTotal -= itemCount * bananaPrice;
                        realAnswer = 1;
                    }
                    //If total count of item is invalid (negative), reverses itemCount subtraction and throws an ERROR
                    else if(bananaCount < 0){
                        printf("ERROR: Total number of bananas is invalid (Negative number)\nPlease try again\n");
                        bananaCount += itemCount;
                    }
                    //If itemCount is an invalid input, throws an ERROR for re-input
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                }
                else {
                    //If they want to cancel the selection
                    scanf("%10s", cancelCode);
                    if(strcmp(cancelCode, "CANCEL") == 0 || strcmp(cancelCode, "cancel") == 0 || strcmp(cancelCode, "Cancel") == 0) {
                        printf("Returning to item selection...\n");
                        realAnswer = 1;
                    }
                    //Assures input entered is valid (not a float or anything else)
                    else {
                        printf("ERROR: Invalid Input!!!\nPlease input an integer value >= 1 OR enter CANCEL to exit banana selection!\n");
                    }
                }
            }
        }
        //Carrot Section
        //This checks for 6 more common results of an input. Can't account for all of them
        else if(strcmp(currentItem, "Carrot") == 0 || strcmp(currentItem, "carrot") == 0 || 
           strcmp(currentItem, "CARROT") == 0 || strcmp(currentItem, "Carrots") == 0 || 
           strcmp(currentItem, "carrots") == 0 || strcmp(currentItem, "CARROTS") == 0) {
            //realAnswer is only changed when a real answer is inputted. 
            while(realAnswer == 0){
                //Displays current total of items for live tracking
                printf("You have %d carrots currently rung up!\n", carrotCount);
                printf("How many carrots are you buying?\nIf you want to remove carrots from the total, input a negative number!\n");
                scanf("%d", &itemCount);
                //Assuming the user wants to add items to the total
                if(itemCount >= 1){
                    //Adds itemCount to total count of item to check if the total number of items is valid (not negative)
                    carrotCount += itemCount;
                    /*If total item count is positive after the change, will add the itemCount of items to subTotal 
                    and also add them to the total count of the item from before */
                    if(carrotCount >= 0){
                        printf("Ok, %d carrots have been added to the total!\n", itemCount);
                        subTotal += itemCount * carrotPrice;
                        realAnswer = 1;
                    }
                    /*If the total count of item is now a negative number (even though it's adding), throws an invalid ERROR
                    and asks for re-input, as well as removing the itemCount from the total to not let invalid numbers through*/
                    else if(carrotCount < 0){
                        printf("ERROR: Total number of carrots is invalid (Negative number)!!!\nPlease try again\n");
                        carrotCount -= itemCount;
                    }
                    /*If the input is some other data type it throws an ERROR and asks for re-input*/
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                    
                }
                //If the input is a negative number, the user wants to subtract items from the total count
                else if(itemCount < 0){
                    //Gets the absolute value of negative number for calculating lines
                    itemCount = abs(itemCount);
                    //Takes away the number of items wanting to be removed from the total item count
                    carrotCount -= itemCount;
                    //If the total item count is still positive, then follows removal of itemCount to total count
                    if(carrotCount >= 0){
                        printf("Ok, removing %d carrots from the total!\n", itemCount);
                        subTotal -= itemCount * carrotPrice;
                        realAnswer = 1;
                    }
                    //If total count of item is invalid (negative), reverses itemCount subtraction and throws an ERROR
                    else if(carrotCount < 0){
                        printf("ERROR: Total number of carrots is invalid (Negative number)\nPlease try again\n");
                        carrotCount += itemCount;
                    }
                    //If itemCount is an invalid input, throws an ERROR for re-input
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                }
                else {
                    //If they want to cancel the selection
                    scanf("%10s", cancelCode);
                    if(strcmp(cancelCode, "CANCEL") == 0 || strcmp(cancelCode, "cancel") == 0 || strcmp(cancelCode, "Cancel") == 0) {
                        printf("Returning to item selection...\n");
                        realAnswer = 1;
                    }
                    //Assures input entered is valid (not a float or anything else)
                    else {
                        printf("ERROR: Invalid Input!!!\nPlease input an integer value >= 1 OR enter CANCEL to exit carrot selection!\n");
                    }
                }
            }
        }
        //Orange Section
        //This checks for 6 more common results of an input. Can't account for all of them
        if(strcmp(currentItem, "Orange") == 0 || strcmp(currentItem, "orange") == 0 || 
           strcmp(currentItem, "ORANGE") == 0 || strcmp(currentItem, "Oranges") == 0 || 
           strcmp(currentItem, "oranges") == 0 || strcmp(currentItem, "ORANGES") == 0) {
            //realAnswer is only changed when a real answer is inputted. 
            while(realAnswer == 0){
                //Displays current total of items for live tracking
                printf("You have %d oranges currently rung up!\n", orangeCount);
                printf("How many oranges are you buying?\nIf you want to remove oranges from the total, input a negative number!\n");
                scanf("%d", &itemCount);
                //Assuming the user wants to add items to the total
                if(itemCount >= 1){
                    //Adds itemCount to total count of item to check if the total number of items is valid (not negative)
                    orangeCount += itemCount;
                    /*If total item count is positive after the change, will add the itemCount of items to subTotal 
                    and also add them to the total count of the item from before */
                    if(orangeCount >= 0){
                        printf("Ok, %d oranges have been added to the total!\n", itemCount);
                        subTotal += itemCount * orangePrice;
                        realAnswer = 1;
                    }
                    /*If the total count of item is now a negative number (even though it's adding), throws an invalid ERROR
                    and asks for re-input, as well as removing the itemCount from the total to not let invalid numbers through*/
                    else if(orangeCount < 0){
                        printf("ERROR: Total number of oranges is invalid (Negative number)!!!\nPlease try again\n");
                        orangeCount -= itemCount;
                    }
                    /*If the input is some other data type it throws an ERROR and asks for re-input*/
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                    
                }
                //If the input is a negative number, the user wants to subtract items from the total count
                else if(itemCount < 0){
                    //Gets the absolute value of negative number for calculating lines
                    itemCount = abs(itemCount);
                    //Takes away the number of items wanting to be removed from the total item count
                    orangeCount -= itemCount;
                    //If the total item count is still positive, then follows removal of itemCount to total count
                    if(orangeCount >= 0){
                        printf("Ok, removing %d oranges from the total!\n", itemCount);
                        subTotal -= itemCount * orangePrice;
                        realAnswer = 1;
                    }
                    //If total count of item is invalid (negative), reverses itemCount subtraction and throws an ERROR
                    else if(orangeCount < 0){
                        printf("ERROR: Total number of oranges is invalid (Negative number)\nPlease try again\n");
                        orangeCount += itemCount;
                    }
                    //If itemCount is an invalid input, throws an ERROR for re-input
                    else{
                        printf("ERROR: Input Invalid!!! Please try again\n");
                    }
                }
                else {
                    //If they want to cancel the selection
                    scanf("%10s", cancelCode);
                    if(strcmp(cancelCode, "CANCEL") == 0 || strcmp(cancelCode, "cancel") == 0 || strcmp(cancelCode, "Cancel") == 0) {
                        printf("Returning to item selection...\n");
                        realAnswer = 1;
                    }
                    //Assures input entered is valid (not a float or anything else)
                    else {
                        printf("ERROR: Invalid Input!!!\nPlease input an integer value >= 1 OR enter CANCEL to exit orange selection!\n");
                    }
                }
            }
        }
        //Exit conditional
        else if(strcmp(currentItem, "Exit") == 0){
            exitCon = 1;
        }
        //Any other input that isn't valid here
        else{
            printf("ERROR: Invalid Input!!!\nPlease try again!\n");
        }
    }
    //Testing to make sure counts are correct
    printf("Apple Count = %d\n", appleCount);
    printf("Banana Count = %d\n", bananaCount);
    printf("Carrot Count = %d\n", carrotCount);
    printf("Orange Count = %d\n", orangeCount);
    
    return 0;
}