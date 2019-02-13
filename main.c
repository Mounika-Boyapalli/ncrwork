#include <stdio.h>         //header file
#include <ctype.h>
#include "counta.h"
#include "replacetab.h"
#include "comments.h"
int main()
{
	int n;                   //defining variables
	printf("\n\tMenu");         //prints the options
	printf("\n1.Count alphabets, digits and special characters");
	printf("\n2.Remove all comments");
	printf("\n3.Replace tab with \t");
	printf("\nEnter your choice");
	scanf_s("%d", &n);                    //scans the option from keyboard

	switch (n)             //switch for performing the selected task
	{
	case 1: counta();       //calls the function which counts the alphabets, digits, spaces and special characters 
		    break;
	case 2: comments();    //calls the function which removes comments
		    break;
	case 3: replacetab();        //calls the function which replaces tab with \t
		    break;

	default: printf("\nInvalid option");
		break;


	}
	getch();
	return 0;
}