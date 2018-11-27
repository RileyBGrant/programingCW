/*
Riley Grant B821369
21/11/2018
Student Loan Repayment Calculator

Assuming that the course didn't start before 2012
Assuming placement is in the third year
Loan payments based on my own loan
*/
#define _CRT_SECURE_NO_WARNINGS //Stops scanf warnings
#include <stdio.h> //Includes the standard input output library
#include <math.h> //Includes the standard libary for mathematical functions

#define TUITION_FEE 9250 //cost to study at university for a year
#define PLACEMENT_FEE 1850 //cost to the uni during a placement year
#define MAINTENANCE_LOAN 4054 //maintenance loan per year
#define MONTHLY_INTEREST 1.0051 //compound interest per month

void GetUserInfo(); //A function to collect the users data
void CalcCosts(); //A function to calculate the total debt once the course has finished

int courseLength = 0;
char placement[4] = "";
int startMonth = 0;
long int startYear = 2011;
char maintenance[4] = "";
double courseCosts = 0;

void main()
{
	GetUserInfo();

	CalcCosts();

	printf("%.2lf", courseCosts);
	scanf("%*s");
}

void GetUserInfo()
{
	printf("How many years long is your course?\n");
	scanf(" %d", &courseLength);

	while (courseLength < 3 || courseLength > 4)
	{
		printf("Invalid course length.\nPlease enter a correct course duration\n");
		scanf(" %d", &courseLength);
	}

	printf("Are you doing a placement year? (Y/N)\n");
	scanf(" %s", &placement);
	if (placement[0] >= 'a' && placement[0] <= 'z')
	{
		placement[0] = placement[0] - 32;
	}

	while (placement[0] != 'Y' && placement[0] != 'N')
	{
		printf("Invalid response, Please answer Y or N\n");
		scanf(" %s", &placement);
		if (placement[0] >= 'a' && placement[0] <= 'z')
		{
			placement[0] = placement[0] - 32;
		}
	}

	printf("What year does your course start? \n");
	scanf(" %ld", &startYear);

	while (startYear < 2012)
	{
		printf("Invalid year, this calculator only works for loan given to courses that start after 2012\n");
		scanf(" %ld", &startYear);
	}

	printf("what month does your course start? (01-12)\n");
	scanf(" %d", &startMonth);

	while (startMonth < 1 || startMonth > 12)
	{
		printf("invalid month, pleasae enter a number from 1-12 for your month\n");
		scanf(" %d", &startMonth);
	}

	printf("Are you taking a maintenance loan? (Y/N)\n");
	scanf(" %s", maintenance);
	if (maintenance[0] >= 'a' && maintenance[0] <= 'z')
	{
		maintenance[0] = maintenance[0] - 32;
	}

	while (maintenance[0] != 'Y' && maintenance[0] != 'N')
	{
		printf("Invalid response, Please answer Y or N\n");
		scanf(" %s", &maintenance);
		if (maintenance[0] >= 'a' &&maintenance[0] <= 'z')
		{
			maintenance[0] = maintenance[0] - 32;
		}
	}
}

void CalcCosts()
{
	int i = 0;
	int j = 0;
	int currentMonth = 0;

	if (placement[0] == 'Y') //adds an extra year to the course if doing a placement
	{
		++courseLength;
		//courseCosts = courseCosts + 1912.40;
	}

	for (i = 0; i < (courseLength * 12); ++i) //steps through the months that pass while studying
	{
		currentMonth = (startMonth + i) % 12; //works out the month of the year

		if (placement[0] == 'Y' && i > 23 && i < 36) //checks if on placement for the month
		{
			switch (currentMonth) //adds the payments to the toatal in the correct month
			{
			case 2:
				courseCosts = courseCosts + (PLACEMENT_FEE / 4);
				break;
			case 5:
				courseCosts = courseCosts + (PLACEMENT_FEE / 4);
				break;
			case 10:
				courseCosts = courseCosts + (PLACEMENT_FEE / 4);
				break;
			}
		}
		else //if not on placement that month
		{
			switch (currentMonth) //adds tuition fees each month
			{
			case 2:
				courseCosts = courseCosts + (TUITION_FEE / 4);
				break;
			case 5:
				courseCosts = courseCosts + (TUITION_FEE / 2);
				break;
			case 10:
				courseCosts = courseCosts + (TUITION_FEE / 4);
				break;
			}

			if (maintenance[0] = 'Y') //adds in the mainenance loan if taken
			{
				switch (currentMonth)
				{
				case 1:
					courseCosts = courseCosts + (MAINTENANCE_LOAN / 3);
					break;
				case 4:
					courseCosts = courseCosts + (MAINTENANCE_LOAN / 3);
					break;
				case 10:
					courseCosts = courseCosts + (MAINTENANCE_LOAN / 3);
					break;
				}
			}
		}

		courseCosts = courseCosts * MONTHLY_INTEREST; //adds the monthly interest


	}
}