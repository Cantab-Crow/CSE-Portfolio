/******************************************************************************
* Author: Hayden Walker
* Program: Payroll Printer
* Purpose: First, gather input data of 3 employees.
*           Second, display information in a formatted table.
* Reflection: Hardest part to do was making sure the printf formatting
*               was satisfactory, such as keeping things in line as well
*               as possible. 
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
	//Declare needed variables first, sorted by number for each
	char employee1[15], employee2[15], employee3[15];
	int age1, age2, age3;
	float salary1, salary2, salary3;

	//Get first employee info
	printf("What is the name of the FIRST employee? : \n");
	scanf("%s", &employee1);
	printf("What is the age of the FIRST employee? : \n");
	scanf("%d", &age1);
	printf("What is the salary of the FIRST employee? : \n");
	scanf("%f", &salary1);
	printf("\n");

	//Get second employee info
	printf("What is the name of the SECOND employee? :\n");
	scanf("%s", &employee2);
	printf("What is the age of the SECOND employee? :\n");
	scanf("%d", &age2);
	printf("What is the salary of the SECOND employee? :\n");
	scanf("%f", &salary2);
	printf("\n");

	//Get third employee info
	printf("What is the name of the THIRD employee? :\n");
	scanf("%s", &employee3);
	printf("What is the age of the THIRD employee? :\n");
	scanf("%d", &age3);
	printf("What is the salary of the THIRD employee? :\n");
	scanf("%f", &salary3);
	printf("\n");

	//Making a fun "Loading Screen" to pretend process
	printf("Loading and compiling table...\n...\n...\n");

	//Now to make the table header
	printf("----------------------------------\n");
	printf("%-15s %-5s %-10s\n", "Name", "Age", "Salary");
	printf("----------------------------------\n");

	//Now the table contents (needs to be formatted)
	printf("%-15s %-5d %6.2f\n", employee1, age1, salary1);
	printf("%-15s %-5d %6.2f\n", employee2, age2, salary2);
	printf("%-15s %-5d %6.2f\n", employee3, age3, salary3);


	return 0;
}