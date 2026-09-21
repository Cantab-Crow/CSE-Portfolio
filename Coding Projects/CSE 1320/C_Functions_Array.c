/*
 * Author:  Hayden Walker
 * Program: Airport Currency Kiosk
 * Purpose: Currency converter menu that uses small functions to exchange currency info
 * Reflection:  Honestly the program itself was quite simple, it was just making sure that 
                invalid inputs were handled correctly was the hardest thing. (SEE: Line 36 - 45)
 */

#include <stdio.h>

//First we declare function prototypes to make sure they'll work later on
//Each function goes one way and has a reciprocal function going the other
double usdToEur(double usd), eurToUsd(double eur);
double usdToGbp(double usd), gbpToUsd(double gbp);
double eurToGbp(double eur), gbpToEur(double gbp);

int main()
{
    //Now to write the menu, which is basically all main will be used for. 
    /*This will be a menu for each 6 operations, running continuously in a while
    loop until the user decides to exit and end the program.*/
    printf("---------------------------------------\n");
    printf("Welcome to the Airport Currency Kiosk!\n");
    printf("---------------------------------------\n");
    
    int running = 1;
    while(running == 1){
        printf("---------------------------------------\n");
        printf("There are 6 conversions available at this station!\n");
        printf("Enter the corresponding number for the conversion, or to exit the kiosk!\n");
        printf("1. USD to EURO      2. EURO to USD\n3. USD to GBP       4. GBP to USD\n5. EURO to GBP       6. GBP to EURO\n7. EXIT\n");
        printf("---------------------------------------\n");
        int convertReq;
        scanf("%d", &convertReq);
        double inputMoney, outputMoney;
        //Code originally had an issue where inputting a non-int character would cause an inifinite loop
        //This small if statement is meant to handle any improper inputs without causing an issue
        if (scanf("%d", &convertReq) != 1) {
            printf("---------------------------------------\n");
            printf("ERROR: Invalid Input!!!\nPlease try again!\n");
            printf("---------------------------------------\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        //Case of USD to EURO
        if(convertReq == 1){
            printf("Enter USD amount to convert to EURO:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            //For a valid input (positive input)
            else if(inputMoney >= 0){
                outputMoney = usdToEur(inputMoney);
                printf("%.2lf USD is %.2lf EURO\n", inputMoney, outputMoney);
            }
            //For anything else
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of EURO to USD
        else if(convertReq == 2){
            printf("Enter EURO amount to convert to USD:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            else if(inputMoney >= 0){
                outputMoney = eurToUsd(inputMoney);
                printf("%.2lf EURO is %.2lf USD\n", inputMoney, outputMoney);
            }
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of USD to GBP
        else if(convertReq == 3){
            printf("Enter USD amount to convert to GBP:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            else if(inputMoney >= 0){
                outputMoney = usdToGbp(inputMoney);
                printf("%.2lf USD is %.2lf GBP\n", inputMoney, outputMoney);
            }
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of GBP to USD
        else if(convertReq == 4){
            printf("Enter GBP amount to convert to USD:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            else if(inputMoney >= 0{
                outputMoney = gbpToUsd(inputMoney);
                printf("%.2lf GBP is %.2lf USD\n", inputMoney, outputMoney);
            }
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of EURO to GBP
        else if(convertReq == 5){
            printf("Enter EURO amount to convert to GBP:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            else if(inputMoney >= 0){
                outputMoney = eurToGbp(inputMoney);
                printf("%.2lf EURO is %.2lf GBP\n", inputMoney, outputMoney);
            }
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of GBP to EURO
        else if(convertReq == 6){
            printf("Enter GBP amount to convert to EURO:\n");
            scanf("%lf", &inputMoney);
            //Makes sure input isn't negative
            if(inputMoney < 0){
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
            else if(inputMoney >= 0){
                outputMoney = gbpToEur(inputMoney);
                printf("%.2lf GBP is %.2lf EURO\n", inputMoney, outputMoney);
            }
            else{
                printf("---------------------------------------\n");
                printf("ERROR: Invalid Input (Negative Number)!!!\nPlease try again!\n");
                printf("---------------------------------------\n");
            }
        }
        //Case of wanting to exit the kiosk. Sets running to 0 to stop while loop after breaking
        else if(convertReq == 7){
            printf("---------------------------------------\n");
            printf("Thank you for choosing Airport Currency Kiosk!\nHave a good day/night!\n");
            printf("---------------------------------------\n");
            running = 0;
        }
        //Default on an invalid input 
        else{
            printf("---------------------------------------\n");
            printf("ERROR: Invalid Input!!!\nPlease try again!\n");
            printf("---------------------------------------\n");
        }
    }
    return 0;
}
//USD to EURO function
double usdToEur(double usd){
    double eur = usd * 0.85;
    return eur;
}
//EURO to USD function
double eurToUsd(double eur){
    double usd = eur * 1.18;
    return usd;
}
//USD to GBP function
double usdToGbp(double usd){
    double gbp = usd * 0.75;
    return gbp;
}
//GBP to USD function
double gbpToUsd(double gbp){
    double usd = gbp * 1.33;
    return usd;
}
//EURO to GBP function
double eurToGbp(double eur){
    double gbp = eur * 0.88;
    return gbp;
}
//GBP to EURO function
double gbpToEur(double gbp){
    double eur = gbp * 1.14;
    return eur;
}
