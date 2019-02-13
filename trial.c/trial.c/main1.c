#include <stdio.h>         //header file

//Function prototypes
void count();
/*void removeC();
void replaceT();
void rotateS(char *);*/
//main function
int main()
{
	int n, l = 0;                   //defining variables
	char s[10];
	printf("\n\tMenu");         //prints the options
	printf("\n1.Count alphabets, digits and special characters");
	printf("\n2.Remove all comments");
	printf("\n3.Find matching word");
	printf("\n4.Replace tab with \t");
	printf("\nEnter your choice");
	scanf_s("%d", &n);                    //scans the option from keyboard
										  //switch for performing the selected task
	switch (n)
	{
	case 1: count();       //calls the function which counts the alphabets, digits, spaces and special characters 
		break;
		/*case 2: removeC();    //calls the function which removes comments
		break;
		case 3: printf("\nEnter the word");    //message for user to enter the word to boe matched in the file
		scanf_s("%s", s);              //scanning the word
		rotateS(s);                 //calling the function which replaces the given word with its rotated version
		break;
		case 4: replaceT();        //calls the function which replaces tab with \t
		break;*/

	default: printf("\nInvalid option");
		break;


	}
	getch();
	return 0;
}