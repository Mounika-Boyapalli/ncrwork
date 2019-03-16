#include <stdio.h>
#include<stdlib.h>
int main()
{
	int input = 0, count = 0, row = 0, num_print = 1, space = 0;
	printf("\nEnter a number");
	scanf_s("%d", &input);
	space = input - 1;
	for (row = 1; row <= input; row++)
	{
		num_print = row;
		for (count = 1; count <= space; count++)
			printf(" ");
		space--;
		for (count = 1; count <= row; count++)
		{
			printf("%d", num_print);
			num_print--;
		}
		num_print = num_print - 2;
		for (count = 1; count < row; count++)
		{
			printf("%d", abs(num_print));
			num_print--;
		}
		printf("\n");
	}
	getch();
	return 0;
}