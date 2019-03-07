#include<stdio.h>
int add1(int, int);
int sub1(int, int);
int mul1(int, int);
int div1(int, int);
int result = -1;
int main()
{
	int variable1 = 0, variable2 = 0, choice = 0;
	printf("\nEnter the variables to be operated upon");
	scanf_s("%d %d", &variable1, &variable2);
	printf("\n   MENU");
	printf("\n1. Addition\n2.Subtraction\n3.Multiply\n4.Division\n");
	printf("\nEnter choice");
	scanf_s("%d", &choice);
	switch (choice)
	{
		case 1:	printf("\n Sum is %d",add1(variable1, variable2));
				break;
		case 2: printf("\nDifference is %d",sub1(variable1, variable2));
				break;
		case 3: printf("\nProduct is %d",mul1(variable1, variable2));
				break;
		case 4: printf("\nQuotient is %d",div1(variable1, variable2));
			    break;
		default:printf("\nInvalid Option");
	}
	getch();
	return 0;
}