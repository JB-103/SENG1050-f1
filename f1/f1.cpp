/*
* FILE : f1.c
* PROJECT : SENG1050 - Focus Assignment #1
* PROGRAMMER : Justin Blake
* FIRST VERSION : 2024-05-14
* DESCRIPTION :
* The functions in this file are used to receive user input, store them, and print the formatted results.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

int fillFlightInfo(struct FlightInfo flights[], char* destination, char* date, int fillCounter);
void printFlightInfo(struct FlightInfo flights[]);

const int kMaxNumStrings = 10;
const int kPairCharLimit = 30;

struct FlightInfo
{
	char* destination;
	char* date;
};

int main(void)
{
	char inputDestination[kPairCharLimit];
	char inputDate[kPairCharLimit];

	FlightInfo flights[kMaxNumStrings] = { 0 };

	for (int counter = 0; counter < kMaxNumStrings; counter++) {
		printf("\nPlease enter a destination:\n");
		fgets(inputDestination, kPairCharLimit, stdin);
		inputDestination[strcspn(inputDestination, "\n")] = '\0';

		printf("\nPlease enter a date:\n");
		fgets(inputDate, kPairCharLimit, stdin);
		inputDate[strcspn(inputDate, "\n")] = '\0';

		if (fillFlightInfo(flights, inputDestination, inputDate, counter) == 0)
		{
			printf("Out of memory.\n");
			return 0;
		};
	}

	printFlightInfo(flights);

	for (int counter = 0; counter < kMaxNumStrings; counter++)
	{
		free(flights[counter].destination);
		free(flights[counter].date);
	}
	return 0;
}

//
// FUNCTION : fillFlightInfo
// DESCRIPTION :
// Stores user input in array of struct variables.
// PARAMETERS :
// flights[]: An array used to store flight information.
// destination: A string containing the user-entered destination.
// date: A string containing the user-entered date.
// fillCounter: A counter used to identify which array elements to fill.
// RETURNS :
// 1: SUCCESS
// 0: ERROR
int fillFlightInfo(struct FlightInfo flights[], char* destination, char* date, int fillCounter)
{
	if ((flights[fillCounter].destination = (char*)malloc(kPairCharLimit)) == NULL)
	{
		return 0;
	}

	if ((flights[fillCounter].date = (char*)malloc(kPairCharLimit)) == NULL)
	{
		return 0;
	}

	strcpy(flights[fillCounter].destination, destination);
	strcpy(flights[fillCounter].date, date);

	return 1;
}

//
// FUNCTION : printFlightInfo
// DESCRIPTION :
// Prints all the elements of the flight arrray.
// PARAMETERS :
// flights[]: The array used to store flight information.
// RETURNS :
// VOID
void printFlightInfo(struct FlightInfo flights[])
{
	for (int counter = 0; counter < kMaxNumStrings; counter++)
	{
		printf("\n%-35s%-35s", flights[counter].destination, flights[counter].date);
	}
}