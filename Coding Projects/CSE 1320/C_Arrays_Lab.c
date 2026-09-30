/******************************************************************************
* Author: Hayden Walker
* Program: Classroom Command Center
* Purpose: Gather student names, rolls, and grades and then display them in a 
            formatted table. Also show average, highest, and lowest grades.
* Reflection: Arrays are just tricky for me in general so I had to look a lot 
            of stuff up to make sure I was doing it right. 
*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100 //Got this as a way to make getting strings for arrays work

int main()
{
    //First, initialize some variables
    //Not the actual arrays, those have to be initialized later, since size is variable 
    int numStudent, startCon = 0;
    
    
    //Start the initial interaction, with a while loop to make sure values are valid
    while(startCon == 0){
        printf("Enter Number of Students to enter Info:\n");
        scanf("%d", &numStudent);
        if(numStudent > 0){
            startCon = 1;
        }
        else if(numStudent <= 0){
            printf("Invalid Input!!!\nEnter a Valid Number\n");
        }
        else{
            printf("Invalid Input!!!\nEnter a Valid Number\n");
        }
    }
    
    //Now initialize arrays with size variable
    char *studentNames[numStudent][MAX_STR_LEN];
    int studentRoll[numStudent];
    float studentGrades[numStudent];
    
    //Temp variables to be used to assign value to arrays
    int tempRoll;
    float tempGrade;
    
    
    //Now to being gathering data, going in order of name, roll number, and grade
    for(int i = 0; i < numStudent; i++){
        printf("\nEnter Student's Name: ");
        scanf(" %s", &studentNames[i]);
        
        printf("Enter Student's Roll Number: ");
        scanf("%d", &tempRoll);
        studentRoll[i] = tempRoll;
        
        printf("Enter Student's Grade: ");
        scanf("%f", &tempGrade);
        studentGrades[i] = tempGrade;
    }
    
    //Now display information, for however many students
    printf("----------------------------------------------\n");
    printf("Student Details: ");
    for(int j = 0; j < numStudent; j++){
        printf("\nStudent %d - Name: %-10s Roll #: %-3d Grade: %.2f\n", j + 1, studentNames[j], studentRoll[j], studentGrades[j]);
    }
    
    //Now to display stats, with their own new variables
    //lowestGrade and highestGrade are tied to the scores array to make sure the logic stays correct
    float sumGrade, lowestGrade = studentGrades[0], highestGrade = studentGrades[0];
    //First is the sumGrade and lowest/highestGrades
    for(int k = 0; k < numStudent; k++){
        //Adds the current evaluated grade to the sum
        sumGrade =+ studentGrades[k];
        
        //Checks for a new highest score
        if (studentGrades[k] > highestGrade) {
            highestGrade = studentGrades[k];
        }
        //Check for a new lowest score
        if (studentGrades[k] < lowestGrade) {
            lowestGrade = studentGrades[k];
        }
    }
    
    //Calculates the average based on the sumGrade total and number of students 
    float averageGrade = sumGrade / numStudent;
    
    //Displays information
    printf("----------------------------------------------\n");
    printf("Average Grade: %.2f\nHighest Grade: %.2f\nLowest Grade: %.2f", averageGrade, highestGrade, lowestGrade);

    return 0;
}
